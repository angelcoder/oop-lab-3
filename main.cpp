#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow w(sf::VideoMode(640, 480), "");

    while (w.isOpen()) {
        sf::Event e;

        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w.close();
        }

        w.clear(sf::Color::Cyan);
        w.display();
    }

    return 0;
}
