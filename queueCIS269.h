/*************************************************************************
* Title: Queue (CIS-269 Assignment #4)
* File: queueCIS269.h
* Author: G. Wagner
* Modified by: James Eli
* Date: 10/21/2018
*
* Queue implemented as circular buffer.
*
* Notes:
*  (1) Circular buffer concepts researched at Chapter 7. Boost.Circular
*      Buffer located here:
*      https://www.boost.org/doc/libs/1_61_0/doc/html/circular_buffer.html
*  (2) Queue (circular buffer) size is fixed at compile time by QUEUE_SIZE
*      constant.
*  (3) Note: when queue (circular buffer) is full, further calls to enqueue
*      are ignored. Many circular buffers continue by overwritting data.
*  (4) Corrected spelling of "peak" to "peek".
*  (5) Compiled/tested with MS Visual Studio 2017 Community (v141), and
*      Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse
*      Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-269.
*************************************************************************
* Change Log:
*   10/21/2018: Initial release. JME
*************************************************************************/
#pragma once

#ifndef _QUEUE_CIS269_H_
#define _QUEUE_CIS269_H_

#include <exception> // out of range

const int QUEUE_SIZE = 5;

template <class T>
class QueueCIS269
{
private:
	T queueArray[QUEUE_SIZE];
	size_t front; // Elements popped from this array index.
	size_t back;  // Elements pushed to this array index.
	bool full;    // True if queue array is full.

public:
	QueueCIS269();
	virtual ~QueueCIS269() = default;

	// adds value to queue
	void enqueue(T);

	// removes value from queue
	void dequeue();

	// checks if queue is empty
	bool isEmpty();

	// checks if queue is full
	bool isFull();

	// shows the value at the front of the queue
	T peekFront();

	// ADDED: shows the value at the back of the queue
	T peekBack();
};

// can move to another file 

template <class T>
QueueCIS269<T>::QueueCIS269() : front(0), back(0), full(false) { }

// implementation of enqueue
template <class T>
void QueueCIS269<T>::enqueue(T val)
{
	if (full)                         // Check if queue full.
		return;

	queueArray[back] = val;           // Insert value into queue.
	back = (back + 1) % QUEUE_SIZE;   // Increment pointer, wrap if necessary.
	full = (back == front);           // Queue full?
}

// removes value from queue
template <class T>
void QueueCIS269<T>::dequeue()
{
	if (isEmpty())	                  // Check if empty.
		return;

	full = false;                     // Queue can not be full.
	front = (front + 1) % QUEUE_SIZE; // Increment pointer (wrap if necessary).
}

// implements the isempty
template <class T>
bool QueueCIS269<T>::isEmpty() { return (!full && (back == front)); }

// implements the isFull
template <class T>
bool QueueCIS269<T>::isFull() { return full; }

// implement the peekFront()
template <class T>
T QueueCIS269<T>::peekFront()
{
	if (isEmpty())
		throw std::out_of_range("empty queue");
	else
		return queueArray[front];
}

// implement the peekBack()
template <class T>
T QueueCIS269<T>::peekBack()
{
	if (isEmpty())
		throw std::out_of_range("empty queue");
	else
		return queueArray[(back ? back - 1 : QUEUE_SIZE - 1)];
}

#endif