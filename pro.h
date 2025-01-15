#include <QApplication>
#include <QFontDatabase>

#include "turbincontrol/turbincontrol.h"
#include "traincontrol//traincontrol.h"
#include "ledcontrol/ledcontrol.h"
#include "switchcontrol/switchcontrol.h"


class MainWindow : public QMainWindow{

Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

private:

    void screenGeometry();

    Traincontrol* wTraincontrol1;
    Traincontrol* wTraincontrol2;

    Ledcontrol* wLedcontrol1;
    Ledcontrol* wLedcontrol2;

    Switchcontrol* wSwitchcontrol;

    Turbincontrol* wTurbincontrol;

    QSize MainWindowSize;
    QPoint MainWindowPos;

    QRect Resolution;

public slots:
    void handleSubWindow(QWidget* Identifier);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
};

