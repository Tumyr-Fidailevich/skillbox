#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QWidget *parent);
    ~MyButton();
    void setUp();
    void setDown();
    void playSound();
private:
    QMediaPlayer *_player;
    QAudioOutput *_audioOut;
    QUrl _soundUrl = QUrl("qrc:/resources/click.mp3");
    QPixmap _buttonUpPixmap = QPixmap(":/resources/red_button_up.png");
    QPixmap _buttonDownPixmap = QPixmap(":/resources/red_button_down.png");
};

#endif
