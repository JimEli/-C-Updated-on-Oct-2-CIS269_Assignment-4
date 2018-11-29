# CIS-269 Assignment #4
Implement a queue as a circular buffer

Notes:
* Circular buffer concepts researched at Chapter 7. Boost.Circular Buffer located here: https://www.boost.org/doc/libs/1_61_0/doc/html/circular_buffer.html
* Queue (circular buffer) size is fixed at compile time by QUEUE_SIZE constant.
* Note: when queue (circular buffer) is full, further calls to enqueue are ignored. Many circular buffers continue by overwritting data.
* Corrected spelling of "peak" to "peek".
* Compiled/tested with MS Visual Studio 2017 Community (v141), and Windows SDK version 10.0.17134.0 (32 & 64-bit), and with Eclipse Oxygen.3a Release (4.7.3a), using CDT 9.4.3/MinGw32 gcc-g++ (6.3.0-1).
