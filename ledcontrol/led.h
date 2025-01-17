#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QDebug>
#include <QMainWindow>
#include <QResizeEvent>
#include <QGridLayout>

#ifndef LEDGRID_H
#define LEDGRID_H

class ledGrid : public QWidget{
    Q_OBJECT


public:

    ledGrid(QWidget* parent,int num,QVector<QRgb> color);


    QVector<QSlider*> Slider;

private:

    int size;

    const int bRESET = 0;
    const int bALL = 1;

    QVector<QRgb> sliderColor;

    QString sliderStyle = R"(
        QSlider::groove:horizontal {
        height: 6px;
        background: transparent;
        margin: 8px;
        border: 1px solid #c17d08;
        border-radius: 12px;
        }

        QSlider::sub-page:horizontal {
        background: rgb(%1,%2,%3);
        height: 6px;
        border-radius: 12px;
        }

        QSlider::add-page:horizontal {
        background: rgb(%4, %5, %6);
        height: 10px;
        border-radius: 12px;
        }

        QSlider::handle:horizontal {
        background: transparent;
        margin: -10px;
        border: 1px solid transparent;
        border-radius: 5px;
        }
    )";

public slots:

    void onResetButtonClicked();
    void onAllButtonClicked();

private slots:
    void onSliderChanged(int sliderIndex);


};


#endif // LEDGRID_H
