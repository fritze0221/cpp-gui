#include "house.h"


House::House(QMainWindow *parent, QString string)
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    newWindowButton = new QPushButton(string, this);

    connect(newWindowButton, &QPushButton::clicked, this, [this]() {
        emit requestOpenSubWindow();
    });

    mainLayout->addWidget(newWindowButton);

    setLayout(mainLayout);
}

