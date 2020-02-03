#include "paddle_player.h"

#include<SFML/Graphics.hpp>

paddle_player::paddle_player(int playerNumber)
{
    switch(this->playerNumber)
        {
            case 0 :
                this->Load("paddle1.png");
                break;
            default:
                this->Load("paddle2.png");
                break;


        }
}
        void paddle_player::Update()
        {
            switch(this->playerNumber)
            {
            case 0 :
                this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::W);
                break;
            default:
                this->velocity.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
                break;

            }
            entity::Update();
            if(this->getPosition().y < 0)
            {
                this->move(0,1.0f);
            }
            if(this->getPosition().y + this->getGlobalBounds().height > 600)
            {
                this->move(0,-1.0f);
            }
        }
