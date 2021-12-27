// Copyright

#ifndef STRING_SOUND_H //NOLINT
#define STRING_SOUND_H

#include <math.h>
#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "CircularBuffer.h"

class StringSound {
 public:
     explicit StringSound(double frequency);
     explicit StringSound(std::vector<sf::Int16> init);
     StringSound(const StringSound &obj) {}
     ~StringSound();
     void pluck();
     void tic();
     sf::Int16 sample();
     int time();

 private:
     CircularBuffer * _cb;
     int _time;
};

#endif//NOLINT
