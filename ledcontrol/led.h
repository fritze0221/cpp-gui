#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QDebug>
#include <QMainWindow>
#include <QResizeEvent>
#include <QGridLayout>


#ifndef LED_H
#define LED_H

class LED : public QWidget{
    Q_OBJECT


public:

    LED(QWidget* parent,int num, QString string);

    QSize LEDSize;
    QPoint LEDPos;

private:

    QPushButton* resetButton;
    QPushButton* allButton;
    QPushButton* quitButton;
    QVector<QSlider*> Slider;

    int size;

    const int bRESET = 0;
    const int bALL = 1;

    const char* sheet1 = R"(
            QSlider::groove:horizontal {
            height: 20px;
            background: #b0b0b0;
            border-radius: 10px;
            }
            QSlider::handle:horizontal {
            width: 20px;
            background: #ffffff;
            border: 1px solid #5c5c5c;
            margin: -5px 0;
            border-radius: 10px;
            }
            )";

    const char* sheet2 = R"(
            QSlider::groove:horizontal {
            height: 20px;
            background: #468641;
            border-radius: 10px;
            }
            QSlider::handle:horizontal {
            width: 20px;
            background: #ffffff;
            border: 1px solid #5c5c5c;
            margin: -5px 0;
            border-radius: 10px;
            }
            )";


private slots:
    void onSliderChanged(int sliderIndex);
    void onButtonClicked(int buttonIndex);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void moveEvent(QMoveEvent *event) override;

};


#endif // LED_H
