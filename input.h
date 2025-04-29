#ifndef INPUT_W
#define INPUT_W

#include <SFML/Graphics.hpp>

using namespace sf;

struct Button
{
    bool P1Up, P2Up, P1Down, P2Down, Escape;
};

class Input
{
private:
    /* data */
    Button button;

public:
    Input();
    void InputHandler(Event event, RenderWindow& window);
    Button getButton(void) const;
};

#endif