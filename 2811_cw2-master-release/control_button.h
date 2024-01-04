#ifndef CONTROL_BUTTON_H
#define CONTROL_BUTTON_H

#include <vector>
#include <QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "the_player.h"

class control_button : public QPushButton {
    Q_OBJECT
public:
    void setWindow(QWidget* window);
    control_button() : QPushButton()
    {
        setMinimumSize(sizeHint());
    };
};

class play_pause_button : public control_button
{
    Q_OBJECT
private:
    ThePlayer* plyr;
public:
    play_pause_button(ThePlayer* player) : control_button()
    {
        plyr = player;
        this->setIcon(QIcon(":/pictures/pause.png"));
        connect(this, SIGNAL(clicked()), this, SLOT(pause_play()));
    };
private slots:
    void pause_play();
};

class dark_lightmode_button : public control_button
{
    Q_OBJECT
public:
    dark_lightmode_button() : control_button()
    {
        this->setIcon(QIcon(":/pictures/moon.png"));
        connect(this, SIGNAL(clicked()), this, SLOT(dark_lightMode()));
    };
private slots:
    void dark_lightMode();
};

class full_smallscreen_button : public control_button
{
    Q_OBJECT
private:
    int full_screen = 0;
    char ori;
    std::vector<QWidget*> *scrns;
public:
    char getSize();
    full_smallscreen_button(char orientation, std::vector<QWidget*> *screens) : control_button()
    {
       ori = orientation;
       scrns = screens;
       this->setIcon(QIcon(":/pictures/fullscreen.png"));
       connect(this, SIGNAL(clicked()), this, SLOT(full_smallScreen()));
    };
private slots:
    void full_smallScreen();
};

class horizontal_vertical_button : public control_button
{
    Q_OBJECT
private:
    int vertical = 0;
    std::vector<QWidget*> *scrns;
public:
    char getOrientation();
    horizontal_vertical_button(std::vector<QWidget*> *screens) : control_button()
    {
       scrns = screens;
       this->setIcon(QIcon(":/pictures/vertical.png"));
       connect(this, SIGNAL(clicked()), this, SLOT(horizontal_vertical()));
    };
private slots:
    void horizontal_vertical();
};

#endif // CONTROL_BUTTON_H
