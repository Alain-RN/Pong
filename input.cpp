#include "input.h"

Input::Input()
{
    button.P1Up = button.P1Down = button.P2Up = button.P2Down = button.Escape = false;
}

void Input::InputHandler(Event event, RenderWindow& window)
{
    if(event.type == Event::Closed || button.Escape)
    {
        window.close();
    }

    if( event.type == Event::KeyPressed )
    {
        switch (event.key.code)
        {
            case Keyboard::Q:
                button.P1Up = true;
                break;
            case Keyboard::A:
                button.P1Down = true;
                break;
            case Keyboard::Up:
                button.P2Up = true;
                break;
            case Keyboard::Down:
                button.P2Down = true;
                break;
            case Keyboard::Escape:
                button.Escape = true;
            default:
                break;
        }
    }

    if( event.type == Event::KeyReleased )
    {
        switch (event.key.code)
        {
            case Keyboard::Q:
                button.P1Up = false;
                break;
            case Keyboard::A:
                button.P1Down = false;
                break;
            case Keyboard::Up:
                button.P2Up = false;
                break;
            case Keyboard::Down:
                button.P2Down = false;
                break;
            default:
                break;
        }
    }
}

Button Input::getButton(void) const
{
    return button;
}