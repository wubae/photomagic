// Copyright [2023] <Wu Li> [legal/copyright]
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

void PhotoMagic::transform(sf::Image& input_image, FibLFSR* lfsr) {
  sf::Vector2u size = input_image.getSize();
  sf::Color pixel;

  // XOR Red, Green, Blue using another new 8-bit integer
  for (unsigned int width = 0; width < size.x; width++) {
    for (unsigned int height = 0; height < size.y; height++) {
      pixel = input_image.getPixel(width, height);
      pixel.r ^= lfsr->generate(8);
      pixel.g ^= lfsr->generate(8);
      pixel.b ^= lfsr->generate(8);
      input_image.setPixel(width, height, pixel);
    }
  }
}
