#include "pong.h"

Input input;
Font font;
Text txt;

float posYP1 = (WIN_HEIGHT - PLAYER_HEIGHT)  / 2; 
float posYP2 = (WIN_HEIGHT - PLAYER_HEIGHT)  / 2; 

float posXBall = ( WIN_WIDTH - RADIUS*2 ) / 2;
float posYBall = ( WIN_HEIGHT - RADIUS*2 ) / 2;

float dx = 0.08f;
float dy = 0.05f;

int scoreP1 = 0;
int scoreP2 = 0;

int main()
{
    ContextSettings options;
    options.antialiasingLevel = 8;
    RenderWindow window(VideoMode(WIN_WIDTH, WIN_HEIGHT), "Pong", Style::Default, options);

    CircleShape ball(RADIUS);
    ball.setPosition(posXBall, posYBall);

    RectangleShape P1(Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    P1.setPosition(30,posYP1);

    RectangleShape P2(Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    P2.setPosition(WIN_WIDTH - 45, posYP2);

    loadFont();
    setText(txt, "Mety");
    txt.setPosition(( WIN_WIDTH - txt.getGlobalBounds().width )/2, 20);

    // Utilisation des Entite
    Entity e1(100.f, 100.f, 50.f, 50.f, Color(100, 100,50));
    e1.drawEntity();
    e1.getForm();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            input.InputHandler(event, window);
        }

        checBtn();

        P1.setPosition(30,posYP1);
        P2.setPosition(WIN_WIDTH - 45, posYP2);
        ball.move(dx, dy);
        setText(txt, to_string(scoreP1) + " | " + to_string(scoreP2));

        if ( ball.getPosition().y <= 0 || ball.getPosition().y + ball.getRadius()*2 >= WIN_HEIGHT ) {
            dy = -dy;
        }

        if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getRadius()*2 >= WIN_WIDTH) {
            if(ball.getPosition().x <= 0)
            {
                ++scoreP1;
            }
            if( ball.getPosition().x + ball.getRadius()*2 >= WIN_WIDTH )
            {
                ++scoreP2;
            }
            ball.setPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
            dx = -dx;
        }

        if (ball.getGlobalBounds().intersects(P1.getGlobalBounds()) || 
            ball.getGlobalBounds().intersects(P2.getGlobalBounds())) {
            dx = -dx;
        }

        window.clear();

        window.draw(txt);
        window.draw(P2);
        window.draw(P1);
        window.draw(ball);
        // window.draw(e1.getForm());

        window.display();
    }
    
    return 0;
}

void loadFont()
{
    if(!font.loadFromFile("./res/venite.ttf"))
    {
        cout << "Erreur de chargement du font" << endl;
    }
}

void setText(Text& text, String t)
{
    text.setString(t);
    text.setFont(font);
    text.setCharacterSize(20);
}

void checBtn()
{
    if(input.getButton().P1Up)
    {
        posYP1 -= SPEED;
        if(posYP1 <= 0)
            posYP1 = 0;
        // setText(txt, "P1 Up");
    }    
    
    if(input.getButton().P2Up)
    {
        posYP2 -= SPEED;
        if(posYP2 <= 0)
            posYP2 = 0;
        // setText(txt, "P2 Up");
    }

    if(input.getButton().P1Down)
    {
        posYP1 += SPEED;
        if(posYP1 >= WIN_HEIGHT - PLAYER_HEIGHT)
            posYP1 = WIN_HEIGHT - PLAYER_HEIGHT;
        // setText(txt, "P1 Down");
    }
    
    if(input.getButton().P2Down)
    {
        if(posYP2 >= WIN_HEIGHT - PLAYER_HEIGHT)
            posYP2 = WIN_HEIGHT - PLAYER_HEIGHT;
        posYP2 += SPEED;
        // setText(txt, "P2 Down");
    }    
    
}