// Copyright [2023] <Wu Li> [legal/copyright]
// pixels.cpp:
// using SFML to load a file, manipulate its pixels, write it to disk

// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window
// PhotoMagic input-file.png output-file.png 1011011000110110
// PhotoMagic output-file.png decoded.png 1011011000110110

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

int main(int argc, char* argv[]) {
    // Create a FibLFSR class with a string seed
    // argv[3] Representing 1011011000110110 from User Input
    FibLFSR Fib(argv[3]);

    // Load Images, If Fails Return -1
    sf::Image image, out;
    // Load Input/Output From Argument 1
    if (!image.loadFromFile(argv[1])) {
        return -1;
    }
    if (!out.loadFromFile(argv[1])) {
        return -1;
    }

    // Vector For Size of Image
    sf::Vector2u size = image.getSize();

    // Textures for Input & Output
    sf::Texture in_texture, out_texture;
    in_texture.loadFromImage(image);
    out_texture.loadFromImage(out);

    // Sprites for Drawing
    sf::Sprite in_sprite, out_sprite;
    in_sprite.setTexture(in_texture);
    out_sprite.setTexture(out_texture);

    // Render Windows
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input Image");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output Image");

    // Transform
    PhotoMagic::transform(image, &Fib);

    // Output
    out_texture.loadFromImage(image, sf::IntRect());

    // Provided Event Loop For Two Windows
    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
           if (event.type == sf::Event::Closed) {
            window1.close();
            }
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
        }
        window1.clear(sf::Color::White);
        window1.draw(in_sprite);
        window1.display();
        window2.clear(sf::Color::White);
        window2.draw(out_sprite);
        window2.display();
        }

        if (!image.saveToFile(argv[2])) {
            return -1;
        }

    return 0;
}
