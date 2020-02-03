#ifndef ENTITY_H
#define ENTITY_H
#include<SFML/Graphics.hpp>
#include<string>
class entity : public sf::Sprite
{
    public:
        entity()
        {
            this->texture = new sf::Texture();
        }
        void Load(std::string filename)
        {
            this->texture->loadFromFile("E:/ball1/" + filename);
            this->setTexture(*this->texture);
        }
        virtual void Update()
        {
            this->move(this->velocity);
        }
        bool CheckCollision(entity* Entity)
        {
            return this->getGlobalBounds().intersects(Entity->getGlobalBounds());
        }
        ~entity()
        {
            delete this->texture;
        }

    private:
        sf::Texture* texture;
    protected:
        sf::Vector2f velocity;
};

#endif // ENTITY_H
