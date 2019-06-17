/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>
#include "drawing.h"

QT_BEGIN_NAMESPACE

class Ui_subwindow
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    drawing *drawingwindow_01;

    void setupUi(QWidget *subwindow)
    {
        if (subwindow->objectName().isEmpty())
            subwindow->setObjectName(QStringLiteral("subwindow"));
        subwindow->resize(400, 300);
        horizontalLayout = new QHBoxLayout(subwindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(subwindow);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        drawingwindow_01 = new drawing();
        drawingwindow_01->setObjectName(QStringLiteral("drawingwindow_01"));
        drawingwindow_01->setGeometry(QRect(0, 0, 380, 280));
        scrollArea->setWidget(drawingwindow_01);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(subwindow);

        QMetaObject::connectSlotsByName(subwindow);
    } // setupUi

    void retranslateUi(QWidget *subwindow)
    {
        subwindow->setWindowTitle(QApplication::translate("subwindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class subwindow: public Ui_subwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
