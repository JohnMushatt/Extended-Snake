// Extended Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include <stdlib.h>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RectangleShape shape;
    sf::RectangleShape newBody;
    newBody.setSize(sf::Vector2f(40,40));
    newBody.setFillColor(sf::Color::Red);
    newBody.setPosition(500,500);
    shape.setSize(sf::Vector2f(50,50));
    shape.setFillColor(sf::Color::Red);
    srand(time(NULL));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
          window.close();
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        int x = shape.getPosition().x;
        int y = shape.getPosition().y;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
          x -= 10;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
          x += 10;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
          y -= 10;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
          y += 10;
        }
        // draw everything here...
        // window.draw(...);
        shape.setPosition(x,y);
        std::vector<sf::RectangleShape> list;
        list.push_back(shape);
        list.push_back(newBody);
        for(int i = 0; i < list.size();i++) {
            window.draw(list.at(i));
        }
        //window.draw(list);
        // end the current frame
        window.display();
        sf::sleep(sf::seconds(.1));

    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
