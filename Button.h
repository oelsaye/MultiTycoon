#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "physics.h"

using namespace sf;
using namespace std;

struct Button : public RectangleShape { //inheriting all of RectangleShape
//Constuctor
Button(b2World &world, float x, float y, float width, float height) {
b2BodyDef bodyDef;
bodyDef.position.Set((x + width/2.0)/pixels_per_meter, (y + height/2.0)/pixels_per_meter);
bodyDef.type = b2_kinematicBody;
bodyDef.linearDamping = 0.00;
b2PolygonShape b2shape;
b2shape.SetAsBox(width/pixels_per_meter/2.0, height/pixels_per_meter/2.0);
b2FixtureDef fixtureDef;
fixtureDef.density = 1.0;
fixtureDef.friction = 0.0;
fixtureDef.restitution = 0.5;
fixtureDef.shape = &b2shape;

this->setSize(Vector2f(width, height));
this->setOrigin(width/2.0, height/2.0);
this->setPosition(x + width/2.0, y + height/2.0);
this->setFillColor(sf::Color::White);
}

int Price;
int Object;


};
