/********************************************************************************
** Form generated from reading UI file 'traincontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINCONTROL_H
#define UI_TRAINCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainControl
{
public:
    QSlider *veloSlider;

    void setupUi(QWidget *TrainControl)
    {
        if (TrainControl->objectName().isEmpty())
            TrainControl->setObjectName("TrainControl");
        TrainControl->resize(498, 386);
        TrainControl->setAutoFillBackground(false);
        veloSlider = new QSlider(TrainControl);
        veloSlider->setObjectName("veloSlider");
        veloSlider->setGeometry(QRect(80, 160, 271, 81));
        veloSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"        height: 6px;\n"
"        background: grey;\n"
"        margin: 8px;\n"
"        border: 1px solid #c17d08;\n"
"        border-radius: 12px;\n"
"        }\n"
"\n"
"        QSlider::sub-page:horizontal {\n"
"        background: #c17d08;\n"
"        height: 6px;\n"
"        border-radius: 12px;\n"
"        }\n"
"\n"
"        QSlider::add-page:horizontal {\n"
"        background: #e9e9e9;\n"
"        height: 10px;\n"
"        border-radius: 12px;\n"
"        }\n"
"\n"
"        QSlider::handle:horizontal {\n"
"        background: transparent;\n"
"        margin: -10px;\n"
"        border: 1px solid transparent;\n"
"        border-radius: 5px;\n"
"        }"));
        veloSlider->setOrientation(Qt::Orientation::Horizontal);

        retranslateUi(TrainControl);

        QMetaObject::connectSlotsByName(TrainControl);
    } // setupUi

    void retranslateUi(QWidget *TrainControl)
    {
        TrainControl->setWindowTitle(QCoreApplication::translate("TrainControl", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrainControl: public Ui_TrainControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINCONTROL_H
