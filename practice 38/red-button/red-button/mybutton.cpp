#include "mybutton.h"
#include <iostream>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{
    _player = new QMediaPlayer;
    _audioOut = new QAudioOutput;
    _player->setAudioOutput(_audioOut);
    setUp();
    _player->setSource(_soundUrl);
    _audioOut->setVolume(100);
}

MyButton::~MyButton()
{
    delete _player;
}

void MyButton::setUp()
{
    this->setIcon(_buttonUpPixmap);
}

void MyButton::setDown()
{
    this->setIcon(_buttonDownPixmap);
}

void MyButton::playSound()
{
    if(!_player->isPlaying())
    {
        std::cout << "Yes" << std::endl;
        _player->play();
    }
}
