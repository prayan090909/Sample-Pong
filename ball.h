#ifndef BALL_H
#define BALL_H
#include"paddle_player.h"
#include"entity.h"
#include"Score.h"
class ball : public entity
{
    public:
        ball(Score* score1, Score* score2, paddle_player* player1 , paddle_player* player2);
        virtual ~ball();
        void Update(sf::RenderWindow* window);

    protected:

    private:
        paddle_player* player1;
        paddle_player* player2;
        Score* score1;
        Score* score2;
};

#endif // BALL_H
