#include <QApplication>
#include <QFontDatabase>

#include "led.h"
#include "house.h"
#include "traincontrol//traincontrol.h"


class MainWindow : public QMainWindow{

Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

private:

    void screenGeometry();

    House* wHouse1;
    House* wHouse2;

    LED* wLED1;
    LED* wLED2;

    Traincontrol* wTraincontrol1;
    Traincontrol* wTraincontrol2;

    QSize MainWindowSize;
    QPoint MainWindowPos;

    QRect Resolution;

public slots:
    void handleSubWindow(QWidget* Identifier);

protected:
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
};

