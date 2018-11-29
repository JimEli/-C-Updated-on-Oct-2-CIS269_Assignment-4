/*************************************************************************
* Title: Queue Driver (CIS-269 Assignment #4)
* File: mainQueue.h
* Author: G. Wagner
* Modified by: James Eli
* Date: 10/21/2018
*
* Driver program demonstrating our Queue implemented as a circular buffer.
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
*  (5) Blockchain information researched in "Mastering Blockchain",
*      2nd Edition, Imram Bashir.
*  (6) Compiled/tested with MS Visual Studio 2017 Community (v141), and
*      Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse
*      Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-269.
*************************************************************************
* Change Log:
*   10/21/2018: Initial release. JME
*************************************************************************/
/*
CIS 269 main function

The base code for the queue assignment

You may change this but it needs to keep the main outcomes, show enqueue, dequeue

*/

#include "..\include\queueCIS269.h"
#include "..\include\block.h" // your block code

// your program driver
int main(int argc, char** argv)
{
	// part one
	QueueCIS269<myBlock::Block> *queue = new QueueCIS269<myBlock::Block>(); // change int to block

	// part two (replace numbers with your blocks)
	queue->enqueue(myBlock::Block(1, (char*)"0", 0, time(0)));
	queue->enqueue(myBlock::Block(2, queue->peekBack().getHash(), 0, time(0)));
	queue->enqueue(myBlock::Block(3, queue->peekBack().getHash(), 0, time(0)));
	std::cout << "Peek value: " << queue->peekFront();
	queue->enqueue(myBlock::Block(4, queue->peekBack().getHash(), 0, time(0)));

	// part three (show the queue as empty)
	queue->dequeue();
	queue->enqueue(myBlock::Block(5, queue->peekBack().getHash(), 0, time(0)));
	queue->enqueue(myBlock::Block(6, queue->peekBack().getHash(), 0, time(0)));

	if (queue->isEmpty())
	{
		std::cout << "The queue is empty" << std::endl;
	}
	else
	{
		std::cout << "The queue is not empty" << std::endl;
	}
	queue->dequeue();
	queue->dequeue();
	queue->dequeue();
	queue->dequeue();
	queue->dequeue();
	if (queue->isEmpty())
	{
		std::cout << "The queue is empty" << std::endl;
	}
	else
	{
		std::cout << "The queue is not empty" << std::endl;
	}

	delete queue;
}