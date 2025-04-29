#ifndef ENTITY
#define ENTITY

#include <SFML/Graphics.hpp>
using namespace sf;

class Entity
{
private:

    float posX;
    float posY;
    float heigh;
    float width;
    Color color;
    RectangleShape form;

public:
    Entity(float posX, float posY,float heigh,float width, Color color);
    void drawEntity();
    RectangleShape getForm(void) const;
};



#endif