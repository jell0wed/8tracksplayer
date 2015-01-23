/********************************************************************************
** Form generated from reading UI file 'gui_qt.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_QT_H
#define UI_GUI_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI_QtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI_QtClass)
    {
        if (GUI_QtClass->objectName().isEmpty())
            GUI_QtClass->setObjectName(QStringLiteral("GUI_QtClass"));
        GUI_QtClass->resize(600, 400);
        menuBar = new QMenuBar(GUI_QtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GUI_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI_QtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GUI_QtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GUI_QtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GUI_QtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUI_QtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GUI_QtClass->setStatusBar(statusBar);

        retranslateUi(GUI_QtClass);

        QMetaObject::connectSlotsByName(GUI_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUI_QtClass)
    {
        GUI_QtClass->setWindowTitle(QApplication::translate("GUI_QtClass", "GUI_Qt", 0));
    } // retranslateUi

};

namespace Ui {
    class GUI_QtClass: public Ui_GUI_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_QT_H
