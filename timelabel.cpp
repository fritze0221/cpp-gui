#include "timelabel.h"

timeLabel::timeLabel(QWidget *parent,QString text)
    : labelText(text)
{

    label = new QLabel(text);

    Fonts customFont;
    label->setFont(customFont);

    QVBoxLayout* layout = new QVBoxLayout();

    layout->addWidget(label);

    setLayout(layout);

}
