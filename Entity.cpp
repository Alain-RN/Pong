#include "Entity.h"

Entity::Entity(float posX, float posY,float heigh,float width, Color color)
{
    this->posX = posX;
    this->posY = posX;
    this->heigh = heigh;
    this->width = width;
    this->color = color;
}

void Entity::drawEntity()
{
    form.setSize(Vector2f(width, heigh));
    form.setPosition(posX, posY);
    form.setFillColor(color);
}

RectangleShape Entity::getForm(void) const
{
    return form;
}