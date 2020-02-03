#ifndef MAIN_STATE_H
#define MAIN_STATE_H
#pragma once
#include"game_state.h"

class main_state : public tiny_state
{
    public:
        void Initialize(sf::RenderWindow* window);
        void Render(sf::RenderWindow* window);
        void Destroy(sf::RenderWindow* window);
        void Update(sf::RenderWindow* window);
    private:
        sf::Text* title;
        sf::Font* font;
        sf::Text* play;
        sf::Text* quit;

        int selected ;

        bool upKey , downKey;


};

#endif // MAIN_STATE_H
