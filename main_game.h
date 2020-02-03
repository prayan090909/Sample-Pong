#ifndef MAIN_GAME_H
#define MAIN_GAME_H
#pragma once
#include"game_state.h"
#include"paddle_player.h"
#include"ball.h"
#include"Score.h"
class main_game : public tiny_state
{
    public:
        void Initialize(sf::RenderWindow* window);
        void Render(sf::RenderWindow* window);
        void Destroy(sf::RenderWindow* window);
        void Update(sf::RenderWindow* window);
    private:
        paddle_player* player1;
        paddle_player* player2;
        ball* ballOrigin;
        Score* score1;
        Score* score2;
        sf::Font* font;




};
#endif // MAIN_GAME_H
