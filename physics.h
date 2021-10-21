//Simple to use BOX2D Api written by Vriesinga

#ifndef PHYSICS_H
#define PHYSICS_H

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace std;
const float PI = 3.14159265359;
const float deg_per_rad = 180.0/PI;
const float pixels_per_meter = 32.0;

typedef b2Body* Block;

namespace physics{
    //creates a block function
    Block createBox(b2World &world, float x, float y, float width, float height, b2BodyType type = b2_dynamicBody) {
        b2BodyDef bodyDef;
        bodyDef.position.Set((x + width/2.0)/pixels_per_meter, (y + height/2.0)/pixels_per_meter);
        bodyDef.type = type;
        bodyDef.linearDamping = 0.05;
        b2PolygonShape b2shape;
        b2shape.SetAsBox(width/pixels_per_meter/2.0, height/pixels_per_meter/2.0);
        b2FixtureDef fixtureDef;
        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.4;
        fixtureDef.restitution = 0.5;
        fixtureDef.shape = &b2shape;

        b2Body* res = world.CreateBody(&bodyDef);
        res->CreateFixture(&fixtureDef);

        sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(width, height));
        shape->setOrigin(width/2.0, height/2.0);
        shape->setPosition(x, y);
        shape->setFillColor(sf::Color::White);

        res->SetUserData(shape);

        return res;
    }

    Block createCircle(b2World &world, float x, float y, float r, b2BodyType type = b2_dynamicBody) {
        b2BodyDef bodyDef;
        bodyDef.position.Set(x/pixels_per_meter, y/pixels_per_meter);
        bodyDef.type = type;
        bodyDef.linearDamping = 0.05;
        b2CircleShape b2shape;

        b2shape.m_radius = r/pixels_per_meter;

        b2FixtureDef fixtureDef;
        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.4;
        fixtureDef.restitution = 0.5;
        fixtureDef.shape = &b2shape;

        b2Body* res = world.CreateBody(&bodyDef);
        res->CreateFixture(&fixtureDef);

        sf::CircleShape* shape1 = new sf::CircleShape(r);
        shape1->setOrigin(r,r);
        shape1->setPosition(x, y);
        shape1->setFillColor(sf::Color::White);

        res->SetUserData(shape1);

        return res;

    }

     //creates a polygon must be between 3 and 8 points with no concavities
      //and points must be specified in a counter clockwise orientation
    Block createPolygon(b2World &world, float x, float y, const vector<sf::Vector2f> &point_array, b2BodyType type = b2_dynamicBody) {
        int n = point_array.size();
        b2Vec2 vertices[n];
        sf::ConvexShape* shape = new sf::ConvexShape(n);
        for (int i = 0; i < n; i++) {
            vertices[i].Set(point_array[i].x/pixels_per_meter, point_array[i].y/pixels_per_meter);
            shape->setPoint(i, point_array[i]);
        }
        b2PolygonShape polygonShape;
        polygonShape.Set(vertices, n);
        b2BodyDef bodyDef;
        bodyDef.position.Set(x/pixels_per_meter, y/pixels_per_meter);
        bodyDef.type = type;
        bodyDef.linearDamping = 0.05;

        b2FixtureDef fixtureDef;
        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.4;
        fixtureDef.restitution = 0.5;
        fixtureDef.shape = &polygonShape;

        b2Body* res = world.CreateBody(&bodyDef);
        res->CreateFixture(&fixtureDef);

        shape->setPosition(x,y);
        shape->setFillColor(sf::Color::White);

        res->SetUserData(shape);

        return res;
    }

    Block createSprite(b2World &world, float x, float y, string triangle_file, const sf::Texture &t) {
        size_t n;
        float vx , vy;
        sf::Sprite* shape = new sf::Sprite(t);
        b2Vec2 vertices[3];
        b2PolygonShape polygonShape;

        b2BodyDef bodyDef;
        bodyDef.position.Set(x/pixels_per_meter, y/pixels_per_meter);
        bodyDef.type = b2_dynamicBody;
        bodyDef.linearDamping = 0.05;

        b2FixtureDef fixtureDef;

        fixtureDef.density = 1.0;
        fixtureDef.friction = 0.4;
        fixtureDef.restitution = 0.5;


        b2Body* res = world.CreateBody(&bodyDef);

        ifstream myfile;
        myfile.open(triangle_file);
        if (!myfile.is_open()) {
            cout<<"No Vertex file located"<<endl;
            return 0;
        }
        else {
            cout<<"Vertex file opened successfully"<<endl;
        }
        myfile>>n;
        cout<<n<<endl;
        for (size_t i= 0; i < n; i++ ) {
            for (size_t j = 0; j < 3; j++) {
                myfile>>vx;
                myfile>>vy;
                vertices[j].Set(vx/pixels_per_meter,vy/pixels_per_meter);
            }
            polygonShape.Set(vertices, 3);
            fixtureDef.shape = &polygonShape;
            res->CreateFixture(&fixtureDef);
        }

        shape->setPosition(x,y);
        res->SetUserData(shape);

        myfile.close();


        return res;
    }

    //function that simulates physics, renders shapes, and steps through one time iteration
    void displayWorld(b2World& world, sf::RenderWindow& render) {
        world.Step(1.0/60, int32(8), int32(3));
        for (b2Body* body=world.GetBodyList(); body!=0;body=body->GetNext()) {
            sf::Shape* shape = static_cast<sf::Shape*>(body->GetUserData());
            shape->setPosition(body->GetPosition().x*pixels_per_meter, body->GetPosition().y*pixels_per_meter);
            shape->setRotation(body->GetAngle()*deg_per_rad);
            render.draw(*shape);
        }
    }

    //function that sets a Texture to a block object
    void setBlockTexture(Block b,const sf::Texture *t1) {
        sf::Shape* shape = static_cast<sf::Shape*>(b->GetUserData());
        shape->setTexture(t1);
    }

    //sets Block Color
    void setBlockColor(Block b, sf::Color c) {
        sf::Shape* shape = static_cast<sf::Shape*>(b->GetUserData());
        shape->setFillColor(c);
    }

    //function that checks collision between two blocks
    bool checkCollision(Block b1, Block b2) {
        for (b2ContactEdge* edge = b1->GetContactList(); edge; edge = edge->next) {
            if (edge->other == b2) {
                if (edge->contact->IsTouching()) {
                   return true;
                }
            }
        }
        return false;
    }

    //checks collision of Block b and any other Block
    bool checkCollision(Block b) {
        for (b2ContactEdge* edge = b->GetContactList(); edge; edge = edge->next) {
            if (edge->contact->IsTouching()) return true;
        }
        return false;
    }

    //function that sets a Block collision id
    //by default all Blocks have an id of 0
    //id rules:
    //If two Blocks have an id of 0 they will collide
    //If two Blocks have different id's they will collide
    //If two Blocks have the same positive id they will collide
    //If two Blocks have the same negative id they will not collide
    void setCollisionID(Block b, int16 id) {
        b2Filter filter;
        for (b2Fixture* f = b->GetFixtureList(); f; f = f->GetNext())
        {
            filter = f->GetFilterData();
            filter.groupIndex = id;
            f->SetFilterData(filter);
        }
    }


    //Moves Block b according to Vector force
    void moveBody(Block b, sf::Vector2f force) {
        b->ApplyLinearImpulseToCenter(b2Vec2(force.x, force.y),1);
    }

    //Spins Block B with an Amplitude (negative amp is counterclockwise)
    void spin(Block b, float amp) {
        b->ApplyAngularImpulse(amp,1);
    }

    //Turns off spin for Block b
    void noSpin(Block b) {
        b->SetFixedRotation(true);
    }

    void noGravity(Block b) {
       b->SetGravityScale(0.0);
    }

    void resetGravity(Block b) {
        b->SetGravityScale(1.0);
    }

    //returns the velocity of Block b as a Vector
    sf::Vector2f getVelocity(Block b) {
        b2Vec2 vel = b->GetLinearVelocity();
        sf::Vector2f sfml_vel(vel.x*pixels_per_meter, vel.y*pixels_per_meter);
        return sfml_vel;
    }

    //function that sets the velocity of a block
    void setVelocity(Block b, sf::Vector2f vel) {
        b->SetLinearVelocity(b2Vec2(vel.x/pixels_per_meter,vel.y/pixels_per_meter));
    }

    //function that keeps the angle of the Block but
    //limits its speed
    void limitVelocity(Block b, float speed)
    {
        b2Vec2 velocity = b->GetLinearVelocity();
        b->SetLinearVelocity((speed/pixels_per_meter)/velocity.Length()*velocity);
    }


    sf::Vector2f getPosition(Block b) {
        sf::Vector2f sfml_pos(b->GetPosition().x*pixels_per_meter, b->GetPosition().y*pixels_per_meter);
        return sfml_pos;
    }

    float getAngle(Block b) {
        return b->GetAngle();
    }

    float getAngleSpeed (Block b) {
        return b->GetAngularVelocity();
    }

    void deleteBlock(b2World &world,Block b) {
        world.DestroyBody(b);
        b->SetUserData(0);
    }

    bool isDestroyed(Block b) {
        if (b->GetUserData() == 0) return true;
        else return false;
    }

    void setGravity(b2World &w, sf::Vector2f g) {
        w.SetGravity(b2Vec2(g.x, g.y));
    }
};

#endif // PHYSICS_H
