// Copyright
#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int capacity) {
     if (capacity >= 1) {
          max = capacity;
          buffer = new int16_t[capacity];
          currentSize = 0;
     } else {
          throw(std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.\n")); //NOLINT
     }
}
CircularBuffer::~CircularBuffer(void) {
     delete buffer;
     buffer = nullptr;
}

int CircularBuffer::size() {
     return currentSize;
}

bool CircularBuffer::isEmpty() {
          return (currentSize == 0);
}

bool CircularBuffer::isFull() {
     return(currentSize == max);
}

void CircularBuffer::enqueue(int16_t x) {
     if (currentSize < max) {
          buffer[currentSize] = x;
          currentSize++;
     } else {
          throw std::runtime_error("enqueue: can't enqueue to a full ring.\n");
     }
}

int16_t CircularBuffer::dequeue() {
     if (currentSize != 0) {
             int16_t ret = buffer[0];
             for (int i = 0; i < max - 1; ++i) {
                  buffer[i] = buffer[i + 1];
             }
             buffer[max - 1] = 0;
             currentSize--;
             return ret;
     } else {
          throw std::runtime_error("dequeue: can't dequeue from an empty ring.\n"); //NOLINT
     }
}

int16_t CircularBuffer::peek() {
     if (!isEmpty()) {
          return buffer[0];
     } else {
          throw std::runtime_error("peek: can't peek at an empty ring.\n");
     }
}
