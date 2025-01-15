#include "pro.h"

MainWindow::MainWindow(QWidget* parent)
:QMainWindow(parent)
{

    screenGeometry();

    // wSwitch = new Switch(this);

    // wHouse1 = new House(this, QString("Haus 1"));
    // wLED1 = new LED(this, 3,QString("LED 1"));

    // wHouse2 = new House(this, QString("Haus 2"));
    // wLED2 = new LED(this, 10, QString("LED 2"));

    //wTrain1 = new Train(this);

    wTraincontrol1 = new Traincontrol(this);
    wTraincontrol2 = new Traincontrol(this);

    wLedcontrol1 = new Ledcontrol(this);
    wLedcontrol2 = new Ledcontrol(this);

    wSwitchcontrol = new Switchcontrol(this);

    wTurbincontrol = new Turbincontrol(this);

    QWidget* centralWidget = new QWidget(this);

    // connect(wHouse1, &House::requestOpenSubWindow, this, [=](){handleSubWindow(wLED1);});
    //connect(wHouse2, &House::requestOpenSubWindow, this, [=](){handleSubWindow(wLED2);});

    QHBoxLayout *trainlayout = new QHBoxLayout();

    trainlayout->addWidget(wTraincontrol1);
    trainlayout->addWidget(wTraincontrol2);

    QVBoxLayout *ledlayout = new QVBoxLayout();

    ledlayout->addWidget(wLedcontrol1);
    ledlayout->addWidget(wLedcontrol2);
    ledlayout->addWidget(wTurbincontrol);

    QVBoxLayout *switchlayout = new QVBoxLayout();

    switchlayout->addWidget(wSwitchcontrol);
    switchlayout->addLayout(trainlayout);

    // QHBoxLayout *mergelayout = new QHBoxLayout();

    // mergelayout->addLayout(ledlayout);
    // mergelayout->addLayout(switchlayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    // mainLayout->addWidget(wSwitch);
    // mainLayout->addWidget(wHouse1);
    // mainLayout->addWidget(wHouse2);
    mainLayout->addLayout(ledlayout);
    mainLayout->addLayout(switchlayout);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Control Panel");

}

void MainWindow::screenGeometry(){


    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {

        Resolution = screen->geometry();
        int width = Resolution.width();
        int height = Resolution.height();

        qDebug() << "Bildschirmauflösung:" << width << "x" << height;
    } else {
        qWarning() << "Kein Bildschirm gefunden.";
    }


}

void MainWindow::handleSubWindow(QWidget* Identifier){

    if(!Identifier->isVisible()){ 

        Identifier->show();
        Identifier->move(MainWindowPos + QPoint(MainWindowSize.width(),0));
    }
    

    else{

        Identifier->close();

    }

}

void MainWindow::resizeEvent(QResizeEvent *event){

    QWidget::resizeEvent(event);

    MainWindowSize = event->size();

}

void MainWindow::moveEvent(QMoveEvent *event){

    QMainWindow::moveEvent(event);

    MainWindowPos = event->pos();

}

