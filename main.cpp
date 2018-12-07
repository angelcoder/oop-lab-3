#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "divideandconqueralgo.h"
#include "javis.h"
#include "graham.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <ctime>
#include <kirpatrick.h>
#include <ctime>
#include <vector>
//#include <SFML/Network.hpp>
using namespace sf;
using namespace std;

int main(){
    int method;
       cin >> method;
       //THERE SHOULD BE A VECTOR OF FUNCTIONS SOON
       //Everything is done incredibly stupid WHAT A SHAME! >>>> Redo soon of course 
       switch (method) {

       case 4:{
           sf::RenderWindow window(sf::VideoMode(1000, 1000), "Kirpatrick");
           srand(time(0));
           vector<PointK> points= {{200, 800}, {200, 700}, {300, 600}, {600, 900}, {200, 400}, {100, 900}, {900, 600}, {600, 200},
            {200, 600}, {0, 0}, {400, 400}, {400, 200}, {200, 200}, {50, 950}, {240, 710}, {380, 640}, {690, 910}, {230, 440},
            {150, 980}, {920, 620}, {620, 220}, {290, 650}, {0, 0}, {450, 450}, {470, 270}, {220, 290}, {55, 995}};
           vector<PointK>  hull = convex_hull(points);
           int n = points.size();
           sf::VertexArray lines(sf::LinesStrip, n);
           CircleShape MyCircle(100.f);
           MyCircle.setFillColor(Color::Green);
           int rads=4;
           MyCircle.setRadius(rads);
           for(int i=0; i<n; i++){
               MyCircle.setPosition(points[i].x, points[i].y);
               window.draw(MyCircle);
           }

           while (window.isOpen()){
               sf::Event event;
               while (window.pollEvent(event)){
                   if (event.type == sf::Event::Closed) window.close();
               }
               for (int i = 0; i < hull.size(); i++){
                   lines[i].position = sf::Vector2f(hull[i].x, hull[i].y);
                   window.display();
                   window.draw(lines);
                  sf::sleep(sf::seconds(0.5));
               }
               window.clear();
           }
           break;
       }

       case 5:{
           sf::RenderWindow window(sf::VideoMode(1000, 1000), "Divide and conquer");
           srand(time(0));
           Point points[] = {{200, 800}, {200, 700}, {300, 600}, {600, 900}, {200, 400}, {100, 900}, {900, 600}, {600, 200},
           {200, 600}, {0, 0}, {400, 400}, {400, 200}, {200, 200}, {50, 950}, {240, 710}, {380, 640}, {690, 910}, {230, 440},
           {150, 980}, {920, 620}, {620, 220}, {290, 650}, {0, 0}, {450, 450}, {470, 270}, {220, 290}, {30, 995}};
           int n = sizeof(points)/sizeof(points[0]);
           vector<Point> hull =  printHull(points, n);

           sf::VertexArray lines(sf::LinesStrip, n);

           CircleShape MyCircle(100.f);
           MyCircle.setFillColor(Color::Green);
           int rads=4;
           MyCircle.setRadius(rads);
           for(int i=0; i<n; i++){
               MyCircle.setPosition(points[i].x, points[i].y);
               window.draw(MyCircle);
           }

           float currentFrame=0;

           while (window.isOpen()){
               sf::Event event;
               while (window.pollEvent(event)){
                   if (event.type == sf::Event::Closed) window.close();
               }
               for (int i = 0; i < hull.size(); i++){
                   lines[i].position = sf::Vector2f(hull[i].x, hull[i].y);
                   window.display();
                   window.draw(lines);
                  sf::sleep(sf::seconds(0.5));
               }
               window.clear();
           }

           break;
       }

       case 6:{
           sf::RenderWindow window(sf::VideoMode(1000, 1000), "Jarvis");
           srand(time(0));
           Point points[] = {{200, 800}, {200, 700}, {300, 600}, {600, 900}, {200, 400}, {100, 900}, {900, 600}, {600, 200},
           {200, 600}, {0, 0}, {400, 400}, {400, 200}, {200, 200}, {50, 950}, {240, 710}, {380, 640}, {690, 910}, {230, 440},
           {150, 980}, {920, 620}, {620, 220}, {290, 650}, {0, 0}, {450, 450}, {470, 270}, {220, 290}, {30, 995}};
           int n = sizeof(points)/sizeof(points[0]);
           vector<Point> hull =  convexHullJ(points, n);

           sf::VertexArray lines(sf::LinesStrip, n);

           CircleShape MyCircle(100.f);
           MyCircle.setFillColor(Color::Green);
           int rads=4;
           MyCircle.setRadius(rads);
           for(int i=0; i<n; i++){
               MyCircle.setPosition(points[i].x, points[i].y);
               window.draw(MyCircle);
           }

           float currentFrame=0;

           while (window.isOpen()){
               sf::Event event;
               while (window.pollEvent(event)){
                   if (event.type == sf::Event::Closed) window.close();
               }
               for (int i = 0; i < hull.size(); i++){
                   lines[i].position = sf::Vector2f(hull[i].x, hull[i].y);
                   window.display();
                   window.draw(lines);
                  sf::sleep(sf::seconds(0.5));
               }
               window.clear();
           }

           break;
       }
       case 7:{
           sf::RenderWindow window(sf::VideoMode(1000, 1000), "Graham");
           srand(time(0));
           Point points[] = {{200, 800}, {200, 700}, {300, 600}, {600, 900}, {200, 400}, {100, 900}, {900, 600}, {600, 200},
           {200, 600}, {0, 0}, {400, 400}, {400, 200}, {200, 200}, {50, 950}, {240, 710}, {380, 640}, {690, 910}, {230, 440},
           {150, 980}, {920, 620}, {620, 220}, {290, 650}, {0, 0}, {450, 450}, {470, 270}, {220, 290}, {30, 995}};
           int n = sizeof(points)/sizeof(points[0]);
           vector<Point> hull =  convexHullG(points, n);

           sf::VertexArray lines(sf::LinesStrip, n);

           CircleShape MyCircle(100.f);
           MyCircle.setFillColor(Color::Green);
           int rads=4;
           MyCircle.setRadius(rads);
           for(int i=0; i<n; i++){
               MyCircle.setPosition(points[i].x, points[i].y);
               window.draw(MyCircle);
           }

           while (window.isOpen()){
               sf::Event event;
               while (window.pollEvent(event)){
                   if (event.type == sf::Event::Closed) window.close();
               }
               for (int i = 0; i < hull.size(); i++){
                   lines[i].position = sf::Vector2f(hull[i].x, hull[i].y);
                   window.display();
                   window.draw(lines);
                  sf::sleep(sf::seconds(0.5));
               }
               window.clear();
           }
           break;
       }

       }

    return 0;
 }


