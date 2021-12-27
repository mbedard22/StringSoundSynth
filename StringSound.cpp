// Copyright

#include "StringSound.h"
std::default_random_engine generator;
std::uniform_int_distribution<sf::Int16> distribution(-32768, 32767);

StringSound::StringSound(double frequency) {
     _cb = new CircularBuffer(ceil(44100/frequency));
     _time = 0;
}
StringSound::StringSound(std::vector<sf::Int16> init) {
     _cb = new CircularBuffer(init.size());
     for (std::vector<sf::Int16>::iterator it = init.begin(); it != init.end(); ++it) {//NOLINT
          int16_t temp = *it;
          _cb->enqueue(temp);
     }
}

StringSound::~StringSound() {
    _cb->~CircularBuffer();
    delete _cb;
    _cb = nullptr;
    _time = 0;
}

void StringSound::pluck() {
     while (!_cb->isEmpty()) {
          _cb->dequeue();
     }

     while (!_cb->isFull()) {
          sf::Int16 rando = (distribution(generator));
          _cb->enqueue(rando);
     }
}
void StringSound::tic() {
     sf::Int16 temp1 = _cb->dequeue();
     sf::Int16 temp2 = _cb->peek();
     _cb->enqueue((.996) * ((temp1 + temp2) / 2));
     _time++;
}
sf::Int16 StringSound::sample() {
    return  _cb->peek();
}
int StringSound::time() {
     return _time;
}
