#ifndef SCORE_H
#define SCORE_H
#include<SFML/Graphics.hpp>
#include<string>
class Score : public sf::Text
{
    public:
        Score(sf::Font &font , unsigned int size);
        void IncrementScore();
        void Update();
        virtual ~Score();

    protected:

    private:
        int value;
};

#endif // SCORE_H
