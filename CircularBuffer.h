#ifndef CIRCULAR_BUFFER_H //NOLINT
#define CIRCULAR_BUFFER_H
// Copyright
#include <iostream>
#include <stdint.h> //NOLINT

class CircularBuffer {
 public:
      explicit CircularBuffer(int capacity);
      ~CircularBuffer(void);
      int size();
      bool isEmpty();
      bool isFull();
      void enqueue(int16_t x);
      int16_t dequeue();
      int16_t peek();
 private:
      int16_t * buffer;
      int currentSize;
      int max;
};

#endif //NOLINT
