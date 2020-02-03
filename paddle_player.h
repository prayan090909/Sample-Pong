#ifndef PADDLE_PLAYER_H
#define PADDLE_PLAYER_H
#include"entity.h"

class paddle_player : public entity
{
    public:
        paddle_player(int playerNumber);
        void Update();



    protected:

    private:
        int playerNumber;
};

#endif // PADDLE_PLAYER_H
