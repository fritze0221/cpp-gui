#ifndef TIMESLIDER_H
#define TIMESLIDER_H

#include <QObject>
#include <QWidget>
#include <QSlider>
#include <QLayout>
#include <QVector>
#include <QPainter>
#include <QEvent>
#include <QStyleOption>
#include <QLabel>
#include <QSpacerItem>

#include "fonts/fonts.h"

class timeSlider : public QWidget
{
    Q_OBJECT
public:
    explicit timeSlider(QWidget *parent,QVector<QRgb> color, int range, int intervall,int scalefactor,int time,QString text);

    QSlider* slider;
    QLabel* label;

private:

    QVector<QRgb> sliderColor;
    int range;
    int intervall;
    int scalefactor;
    int time;

    Fonts customfont;
    QString labelText;

    const int min_width = 30;
    const int min_height = 100;
    const int man_off_x = 0;
    const int man_off_y = -6;

    QString sliderStyle = R"(
        QSlider::groove:vertical {
        width: 6px;
        background: transparent;
        margin: 8px;
        border: 1px solid #c17d08;
        border-radius: 12px;
        }

        QSlider::sub-page:vertical {
        background: rgb(%1,%2,%3);
        width: 6px;
        border-radius: 12px;
        }

        QSlider::add-page:vertical {
        background: rgb(232, 218, 218);
        width: 10px;
        border-radius: 12px;
        }

        QSlider::handle:vertical {
        background: transparent;
        margin: -10px;
        border: 1px solid transparent;
        border-radius: 5px;
        }
    )";

protected:

    void paintEvent(QPaintEvent *event) override;

signals:

    void sendTime(int time);

private slots:

    void onValueChanged();

};

#endif // TIMESLIDER_H
