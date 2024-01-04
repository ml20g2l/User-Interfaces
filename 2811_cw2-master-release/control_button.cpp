#include "control_button.h"

int dark;

void control_button::setWindow(QWidget* window)
{
    window->show();
}

void play_pause_button::pause_play()
{
    switch(this->plyr->state())
    {
        case QMediaPlayer::State::StoppedState:
            this->plyr->play();
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkpause.png"));
            } else if(dark == 0)
            {
                this->setIcon(QIcon(":/pictures/pause.png"));
            }
            break;
        case QMediaPlayer::State::PlayingState:
            this->plyr->pause();
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkplay.png"));
            } else if(dark == 0)
            {
                this->setIcon(QIcon(":/pictures/play.png"));
            }
            break;
        case QMediaPlayer::State::PausedState:
            this->plyr->play();
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkpause.png"));
            } else if(dark == 0)
            {
                this->setIcon(QIcon(":/pictures/pause.png"));
            }
            break;
    default:
        break;
    }
}

void dark_lightmode_button::dark_lightMode()
{
    switch(dark)
    {     
    case 0:
        dark = 1;
        this->setIcon(QIcon(":/pictures/sun.png"));
        //window->setStyleSheet("background-color:black;");
        break;
    case 1:
        dark = 0;
        this->setIcon(QIcon(":/pictures/moon.png"));
        //window->setStyleSheet("background-color:lightgreen;");
        break;
    default:
        break;
    }
}

void full_smallscreen_button::full_smallScreen()
{
    switch(this->full_screen)
    {
        case 0:
            setWindow(this->scrns[0][2]);
            this->full_screen = 1;
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darksmallscreen.png"));
            } else if(dark == 0)
            {
                this->setIcon(QIcon(":/pictures/smallscreen.png"));
            }
            break;
        case 1:
            if(ori == 'h')
            {
                setWindow(this->scrns[0][1]);
            } else if(ori == 'v')
            {
                setWindow(this->scrns[0][1]);
            }
            this->full_screen = 0;
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkfullscreen.png"));
            } else if(dark == 0)
            {
                this->setIcon(QIcon(":/pictures/fullscreen.png"));
            }
            break;
    default:
        break;
    }
}

char full_smallscreen_button::getSize()
{
    return this->full_screen;
}

void horizontal_vertical_button::horizontal_vertical()
{
    switch(this->vertical)
    {
        case 0:
            setWindow(this->scrns[0][1]);
            this->vertical = 1;
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkhorizontal.png"));
            } else
            {
                this->setIcon(QIcon(":/pictures/horizontal.png"));
            }
            break;
        case 1:
            setWindow(this->scrns[0][0]);
            this->vertical = 0;
            if(dark == 1)
            {
                this->setIcon(QIcon(":/pictures/darkvertical.png"));
            } else
            {
                this->setIcon(QIcon(":/pictures/vertical.png"));
            }
            break;
    default:
        break;
    }
}

char horizontal_vertical_button::getOrientation()
{
    return this->vertical;
}

