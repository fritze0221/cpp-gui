#include "led.h"

LED::LED(QWidget *parent,int num, QString string)
    : size(num)
{

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
        Slider[i]->setStyleSheet(sheet1);

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

    setWindowTitle(string);

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
        Slider[sliderIndex]->setStyleSheet(sheet2);
    }

    if (value == 0){
        Slider[sliderIndex]->setStyleSheet(sheet1);
    }
}

void LED::resizeEvent(QResizeEvent *event){

    QWidget::resizeEvent(event);

    LEDSize = event->size();

}

void LED::moveEvent(QMoveEvent *event){

    QWidget::moveEvent(event);

    LEDPos = event->pos();

}

