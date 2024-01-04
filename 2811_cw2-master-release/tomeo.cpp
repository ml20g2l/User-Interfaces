//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "the_player.h"
#include "the_button.h"
#include "control_button.h"
#include <QLabel>
#include <QSlider>

using namespace std;

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn (std::string loc) {

    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::information(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! Add command line argument to \"quoted\" file location."));
        exit(-1);
    }

    // the widget that will show the video
    QVideoWidget *videoWidget = new QVideoWidget;
    videoWidget->setStyleSheet("background-color:black;");

    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;
    player->setVideoOutput(videoWidget);

    QVBoxLayout *horizontal, *vertical, *fullScreen;
    QWidget* hWindow = new QWidget;
    QWidget* vWindow = new QWidget;
    QWidget* fSWindow = new QWidget;

    std::vector<QWidget*> *fullSmallScreens = new vector<QWidget*>(3);
    fullSmallScreens->push_back(hWindow);
    fullSmallScreens->push_back(vWindow);
    fullSmallScreens->push_back(fSWindow);

    std::vector<QWidget*> *formats  = new vector<QWidget*>(2);
    fullSmallScreens->push_back(hWindow);
    fullSmallScreens->push_back(vWindow);

    // the row of video control buttons (play/pause, fullscreen/smallscreen)
    QWidget *hVidCtrlWidget = new QWidget();
    QWidget *vVidCtrlWidget = new QWidget();
    QWidget *vVolumeWidget = new QWidget();
    QWidget *fSVidCtrlWidget = new QWidget();
    // video control buttons are arranged horizontally
    QHBoxLayout *hVCLayout = new QHBoxLayout();
    QHBoxLayout *vVCLayout = new QHBoxLayout();
    QHBoxLayout *vVolLayout = new QHBoxLayout();
    QHBoxLayout *fSVCLayout = new QHBoxLayout();
//    hVidCtrlWidget->setStyleSheet("background-color:lightgreen;");
//    vVidCtrlWidget->setStyleSheet("background-color:lightgreen;");
//    fSVidCtrlWidget->setStyleSheet("background-color:lightgreen;");
    hVidCtrlWidget->setLayout(hVCLayout);
    vVidCtrlWidget->setLayout(vVCLayout);
    vVolumeWidget->setLayout(vVolLayout);
    fSVidCtrlWidget->setLayout(fSVCLayout);

    // creating the play button
    play_pause_button *hPlayButton = new play_pause_button(player);
    play_pause_button *vPlayButton = new play_pause_button(player);
    play_pause_button *fSPlayButton = new play_pause_button(player);
    //fSPlayButton->setStyleSheet("background-color:lightgreen;");
    // adding the button to the video control layout
    hVCLayout->addWidget(hPlayButton);
    vVCLayout->addWidget(vPlayButton);
    fSVCLayout->addWidget(fSPlayButton);

    // creating the dark mode button
    dark_lightmode_button *hDarkModeButton = new dark_lightmode_button();
    dark_lightmode_button *vDarkModeButton = new dark_lightmode_button();
    //darkModeButton->setStyleSheet("background-color:lightgreen;");
    // adding the button to the video control layouts
    hVCLayout->addWidget(hDarkModeButton);
    vVCLayout->addWidget(vDarkModeButton);
    //fSVCLayout->addWidget(darkModeButton);

    // creating the fullscreen button
    horizontal_vertical_button *hHorVertButton = new horizontal_vertical_button(formats);
    horizontal_vertical_button *vHorVertButton = new horizontal_vertical_button(formats);
    //fSFullScreenButton->setStyleSheet("background-color:lightgreen;");
    // adding the button to the video control layout
    hVCLayout->addWidget(hHorVertButton);
    vVCLayout->addWidget(vHorVertButton);

    // creating the fullscreen button
    full_smallscreen_button *hFullScreenButton = new full_smallscreen_button('h', fullSmallScreens);
    full_smallscreen_button *vFullScreenButton = new full_smallscreen_button('v', fullSmallScreens);
    full_smallscreen_button *fSFullScreenButton = new full_smallscreen_button('h', fullSmallScreens);
    //fSFullScreenButton->setStyleSheet("background-color:lightgreen;");
    // adding the button to the video control layout
    hVCLayout->addWidget(hFullScreenButton);
    vVCLayout->addWidget(vFullScreenButton);
    fSVCLayout->addWidget(fSFullScreenButton);

    //create volume slider and makes it horizontal
    QSlider *volSlider = new QSlider(Qt::Horizontal);
    //setting all of the dimensions of the slider
    volSlider->setRange(0,100);
    volSlider->setFixedWidth(200);
    volSlider->setValue(100);
    //volSlider->setStyleSheet("QSlider::handle:horizontal {background-color: lightgreen;}");
    volSlider->connect(volSlider, SIGNAL(valueChanged(int)), player, SLOT (setVolume(int)));
    QSlider *hVolSlider = volSlider;
    QSlider *vVolSlider = volSlider;
    //connects slot/signal of the slider so that the user can adjust the volume
    // adding the slider to the video control layout
    hVCLayout->addWidget(hVolSlider);
    vVolLayout->addWidget(vVolSlider);

    // widget containing tomeo image
    QWidget *tomeoWidget = new QWidget();
    QHBoxLayout *tLayout = new QHBoxLayout();
    tomeoWidget->setLayout(tLayout);
    QLabel *tomeo = new QLabel();
    QPixmap tomeoPic(":/pictures/tomeologo.png");
    tomeo->setAlignment(Qt::AlignCenter);
    tomeo->setPixmap(tomeoPic);
    tomeo->setScaledContents(true);
    tLayout->addWidget(tomeo);

    // widget containing next video label
    QWidget *labelWidget = new QWidget();
    QHBoxLayout *lLayout = new QHBoxLayout();
    labelWidget->setLayout(lLayout);
    // creating the next video label
    QLabel *nextVideo = new QLabel("Select next video:");
    // aligning the label to the centre of the screen
    nextVideo->setAlignment(Qt::AlignCenter);
    // setting the text to bold and increasing the font size of the text
    QFont nVFont = nextVideo->font();
    nVFont.setPointSize(20);
    nVFont.setBold(true);
    nextVideo->setFont(nVFont);
    nextVideo->setStyleSheet("color:white");
    // adding the label to the label layout
    lLayout->addWidget(nextVideo);

    // a row of buttons
    QWidget *hButtonWidget = new QWidget();
    QWidget *vButtonWidget = new QWidget();
    // a list of the buttons
    std::vector<TheButton*> hButtons;
    std::vector<TheButton*> vButtons;
    // the buttons are arranged horizontally for the horizontal layout
    QHBoxLayout *hBLayout = new QHBoxLayout();
    hButtonWidget->setLayout(hBLayout);
    // the buttons are arranged in 2 horizontal widgets for the vertical layout
    QGridLayout *vBLayout = new QGridLayout();
    vButtonWidget->setLayout(vBLayout);

    // create the four buttons for horizontal layout
    for ( int i = 0; i < 4; i++ ) {
        TheButton *hButton = new TheButton(hButtonWidget);
        hButton->connect(hButton, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        hButtons.push_back(hButton);
        hBLayout->addWidget(hButton);
        //hButton->setStyleSheet("background-color:lightgreen;");
        hButton->init(&videos.at(i));
    }

    // create the four buttons for the grid in the vertical layout
    for ( int j = 0; j < 4; j++ )
    {
        TheButton *vButton = new TheButton(vButtonWidget);
        vButton->connect(vButton, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        vButtons.push_back(vButton);
        //vButton->setStyleSheet("background-color:lightgreen;");
        vButton->init(&videos.at(j));
    }

    vBLayout->addWidget(vButtons[0], 0, 0, 1, 1);
    vBLayout->addWidget(vButtons[1], 0, 1, 1, 1);
    vBLayout->addWidget(vButtons[2], 1, 0, 1, 1);
    vBLayout->addWidget(vButtons[3], 1, 1, 1, 1);

    horizontal = new QVBoxLayout();
    horizontal->addWidget(tomeoWidget);
    horizontal->addWidget(videoWidget);
    horizontal->addWidget(hVidCtrlWidget);
    horizontal->addWidget(labelWidget);
    horizontal->addWidget(hButtonWidget);

    vertical = new QVBoxLayout();
    vertical->addWidget(tomeoWidget);
    vertical->addWidget(videoWidget);
    vertical->addWidget(vVidCtrlWidget);
    vertical->addWidget(vVolumeWidget);
    vertical->addWidget(labelWidget);
    vertical->addWidget(vButtonWidget);

    fullScreen = new QVBoxLayout();
    fullScreen->addWidget(videoWidget);
    fullScreen->addWidget(fSVidCtrlWidget);

    // create the main window and layout
    vWindow->setLayout(vertical);
    vWindow->setWindowTitle("Tomeo");
    vWindow->setFixedSize(480, 900);

    hWindow->setLayout(horizontal);
    hWindow->setWindowTitle("Tomeo");
    hWindow->setFixedSize(900, 480);

    fSWindow->setLayout(fullScreen);
    fSWindow->setWindowTitle("Tomeo");
    fSWindow->setFixedSize(900, 480);
    fSWindow->setStyleSheet("background-color:black;");
    fSPlayButton->setIcon(QIcon(":/pictures/darkpause.png"));
    fSFullScreenButton->setIcon(QIcon(":/pictures/darkfullscreen.png"));

    int layout = 1;
    int dark = 0;

    if(dark == 1)
    {
        hWindow->setStyleSheet("background-color:black;");
        hPlayButton->setIcon(QIcon(":/pictures/darkpause.png"));
        hDarkModeButton->setIcon(QIcon(":/pictures/sun.png"));
        hFullScreenButton->setIcon(QIcon(":/pictures/darkfullscreen.png"));

        vWindow->setStyleSheet("background-color:black;");
        vPlayButton->setIcon(QIcon(":/pictures/darkpause.png"));
        vDarkModeButton->setIcon(QIcon(":/pictures/sun.png"));
        vFullScreenButton->setIcon(QIcon(":/pictures/darkfullscreen.png"));
    } else
    {
        hWindow->setStyleSheet("background-color:lightgreen;");
        vWindow->setStyleSheet("background-color:lightgreen;");
        fSWindow->setStyleSheet("background-color:lightgreen;");
    }

    if(layout == 0)
    {
        player->setContent(&hButtons, &videos);
        hWindow->show();

//        for(int i = 0; i < horizontal->count(); ++i)
//        {
//            wdgt = fullScreen->itemAt(i)->widget();
//            if(dark == 1)
//            {
//                window.setStyleSheet("background-color:black;");
//                wdgt->setStyleSheet("background-color:black;");
//                hPlayButton->setIcon(QIcon(":/pictures/darkpause.png"));
//                hDarkModeButton->setIcon(QIcon(":/pictures/sun.png"));
//                hFullScreenButton->setIcon(QIcon(":/pictures/darkfullscreen.png"));
//            } else
//            {
//                window.setStyleSheet("background-color:lightgreen;");
//                wdgt->setStyleSheet("background-color:lightgreen;");
//            }
//        }
    }

    if(layout == 1)
    {
        player->setContent(&vButtons, &videos);
        vWindow->show();
//        for(int j = 0; j < vertical->count(); ++j)
//        {
//            wdgt = vertical->itemAt(j)->widget();
//            if(dark == 1)
//            {
//                vWindow->setStyleSheet("background-color:black;");
//                vPlayButton->setIcon(QIcon(":/pictures/darkpause.png"));
//                vDarkModeButton->setIcon(QIcon(":/pictures/sun.png"));
//                vFullScreenButton->setIcon(QIcon(":/pictures/darkfullscreen.png"));
//            } else
//            {
//                vWindow->setStyleSheet("background-color:lightgreen;");
//            }
//        }
    }


    if(layout == 2)
    {
        player->setContent(&hButtons, &videos);
        fSWindow->show();
    }

    // wait for the app to terminate
    return app.exec();
}
