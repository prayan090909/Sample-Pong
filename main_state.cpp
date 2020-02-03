#include "main_state.h"
#include"main_game.h"
#include<iostream>
void main_state::Initialize(sf::RenderWindow* window)
{
    bool quitGame = false;
    this->selected = 0;
    this->font = new sf::Font();
    this->font->loadFromFile("E:/ball1/DS-DIGIT.ttf");
    this->title = new sf::Text("Ping",*this->font,256U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2 , this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2 , window->getSize().y / 6);

    this->play = new sf::Text("Play",*this->font,128U);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2 , this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2 , window->getSize().y / 2);

    this->quit = new sf::Text("Quit",*this->font,64U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2 , this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2 , window->getSize().y / 1.1);
}
void main_state::Render(sf::RenderWindow* window)
{
    this->play->setColor(sf::Color::White);
    this->quit->setColor(sf::Color::White);
    switch (this->selected)
        {
        case 0 :
            this->play->setColor(sf::Color::Green);
            break;
        case 1 :
            this->quit->setColor(sf::Color::Green);
            break;
        }

    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);

}
void main_state::Destroy(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;
    delete this->play;
    delete this->quit;
}
void main_state::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->upKey)
    {
        this->selected -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !this->downKey)
    {
        this->selected += 1;
    }
    if(this->selected > 1)
    {
        this->selected = 0;
    }
    if(this->selected < 0)
    {
       this->selected = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        switch(this->selected)
        {
        case 0 :
            coreState.SetState(new main_game());
            break;
        case 1 :
            quitGame = true;
            break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

}

