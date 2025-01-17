#include "led.h"

LED::LED(QWidget *parent,int num, QVector<QRgb> color)
    : size(num)
{
    sliderColor << color;

    for(int i = 0; )

    qBound(0,i,3);

    Slider.resize(num);

    QGridLayout *grid = new QGridLayout;

    int j = 0;
    int k = 0;

    for (int i = 0; i < num; i++)
    {

        Slider[i] = new QSlider(Qt::Horizontal);
        Slider[i]->setMaximum(1);
        Slider[i]->setMinimum(0);
        Slider[i]->setTickPosition(QSlider::TicksBelow);
        Slider[i]->setTickInterval(1);
        Slider[i]->setStyleSheet(sliderStyle.arg(qRed(sliderColor[0])).arg(qGreen(sliderColor[0])).arg(qBlue(sliderColor[0])).arg(qRed(sliderColor[1])).arg(qGreen(sliderColor[1])).arg(qBlue(sliderColor[1])));

        connect(Slider[i], &QSlider::valueChanged, this, [=]()
                { onSliderChanged(i); });

        grid->addWidget(Slider[i], j, k);

        k++;

        if (k == 3)
        {

            k = 0;
            j++;
        }
    }


    resetButton = new QPushButton("Reset", this);
    allButton = new QPushButton("All On ", this);
    QHBoxLayout *hbutton = new QHBoxLayout;

    connect(resetButton, &QPushButton::clicked, this, [=]()
            { onButtonClicked(bRESET); });
    connect(allButton, &QPushButton::clicked, this, [=]()
            { onButtonClicked(bALL); });

    hbutton->addWidget(resetButton);
    hbutton->addWidget(allButton);

    QVBoxLayout *row = new QVBoxLayout;

    row->addLayout(grid);
    row->addLayout(hbutton);

    setLayout(row);
}

void LED::onButtonClicked(int buttonindex)
{

    qDebug() << "Button: " << buttonindex;

    if (buttonindex == bRESET)
        for (int i = 0; i < size; i++)
            Slider[i]->setValue(0);

    if (buttonindex == bALL)
        for (int i = 0; i < size; i++)
            Slider[i]->setValue(1);
}

void LED::onSliderChanged(int sliderIndex)
{

    qDebug() << "Slider: " << sliderIndex;

    int value = Slider[sliderIndex]->value();

    if (value == 1){
        Slider[sliderIndex]->setStyleSheet(sliderStyle.arg(qRed(sliderColor[2])).arg(qGreen(sliderColor[2])).arg(qBlue(sliderColor[2])).arg(qRed(sliderColor[3])).arg(qGreen(sliderColor[3])).arg(qBlue(sliderColor[3])));
    }

    if (value == 0){
        Slider[sliderIndex]->setStyleSheet(sliderStyle.arg(qRed(sliderColor[0])).arg(qGreen(sliderColor[0])).arg(qBlue(sliderColor[0])).arg(qRed(sliderColor[1])).arg(qGreen(sliderColor[1])).arg(qBlue(sliderColor[1])));
    }
}


