#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.h"
#include "Entity.h"

using namespace std;
using namespace sf;

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

const float PLAYER_WIDTH = 15.f;
const float PLAYER_HEIGHT = 100.f;
const float SPEED = 0.15f;

const int RADIUS = 14;
void loadFont();
void setText(Text& txt, String t);
void checBtn();
