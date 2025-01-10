/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QPushButton *pushButton;

    void setupUi(QFrame *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName("Frame");
        Frame->resize(400, 300);
        pushButton = new QPushButton(Frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 170, 97, 29));

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QFrame *Frame)
    {
        Frame->setWindowTitle(QCoreApplication::translate("Frame", "Frame", nullptr));
        pushButton->setText(QCoreApplication::translate("Frame", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
