// Copyright
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound *gs) {
     std::vector<sf::Int16> samples;
     gs->pluck();
     int duration = 8;
     int i;
     for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
          gs->tic();
          samples.push_back(gs->sample());
     }
     return samples;
}

int main() {
     sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound"); //NOLINT
     sf::Event event;
     std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
     std::vector<sf::Int16> samples[37];
     sf::Sound sound[37];
     sf::SoundBuffer buf[37];
     for (int i = 0; i < 37; i++) {
          StringSound gs(440 * pow(2.0, (i-24) / 12.0));
          samples[i] = makeSamples(&gs);
          buf[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, 44100);
          sound[i].setBuffer(buf[i]);
     }
     while (window.isOpen()) {
          while (window.pollEvent(event)) {
               if (event.type == sf::Event::Closed) {
                    window.close();
               } else if (event.type == sf::Event::TextEntered) {
                    int i = keys.find(event.text.unicode);
                    if (i >= 0 && i <= 36) {
                         sound[i].play();
                    }
               }
          }
          window.clear();
          window.display();
     }
     return 0;
}
