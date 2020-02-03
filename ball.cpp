#include "ball.h"
#include<SFML/Graphics.hpp>
ball::ball(Score* score1, Score* score2, paddle_player* player1 , paddle_player* player2)
{
    this->Load("ball.png");
    this->player1 = player1;
    this->player2 = player2;
    this->score1 = score1;
    this->score2 = score2;


    this->velocity.x = 0.1f;
    this->velocity.y = 0.1f;


}

ball::~ball()
{

}
void ball::Update(sf::RenderWindow* window)
{
    if(this->CheckCollision(this->player1) || this->CheckCollision(this->player2))
    {
        this->velocity.x *= -1;
    }
    if(this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
    }
    if(this->getPosition().x < 0)
    {
        this->score1->IncrementScore();
        this->setPosition(window->getSize().x / 2 , window->getSize().y / 2);
    }
    if(this->getPosition().x > window->getSize().x + this->player2->getGlobalBounds().width)
    {
        this->score2->IncrementScore();
        this->setPosition(window->getSize().x / 2 , window->getSize().y / 2);
    }
    entity::Update();
}
