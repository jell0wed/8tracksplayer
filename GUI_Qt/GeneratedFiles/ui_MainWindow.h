/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExplorer;
    QAction *actionProfil;
    QAction *actionQuitter;
    QAction *actionEn_cours;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabMainWidget;
    QWidget *tabExplore;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *vLayout1;
    QGroupBox *grpMain;
    QHBoxLayout *horizontalLayout_6;
    QGridLayout *gridLayout_2;
    QGroupBox *grpHotMixes;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widgHotMixes;
    QGroupBox *grpExplore;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *vLayout2;
    QWidget *widgExplore;
    QHBoxLayout *hLayout1;
    QPushButton *btnExplore;
    QWidget *tabSearch;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout;
    QLabel *lblSearch;
    QLineEdit *txtSearch;
    QLabel *lblOrder;
    QComboBox *cmbOrder;
    QPushButton *btnSearch;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QGroupBox *grpSearchMixes;
    QHBoxLayout *horizontalLayout_10;
    QGridLayout *grdSearchMixes;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1024, 700));
        MainWindow->setMaximumSize(QSize(1024, 16777215));
        actionExplorer = new QAction(MainWindow);
        actionExplorer->setObjectName(QStringLiteral("actionExplorer"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/explore_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExplorer->setIcon(icon);
        actionProfil = new QAction(MainWindow);
        actionProfil->setObjectName(QStringLiteral("actionProfil"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/user_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProfil->setIcon(icon1);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/Resources/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuitter->setIcon(icon2);
        actionEn_cours = new QAction(MainWindow);
        actionEn_cours->setObjectName(QStringLiteral("actionEn_cours"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/Resources/playing_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEn_cours->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabMainWidget = new QTabWidget(centralwidget);
        tabMainWidget->setObjectName(QStringLiteral("tabMainWidget"));
        tabMainWidget->setMinimumSize(QSize(800, 300));
        tabMainWidget->setElideMode(Qt::ElideNone);
        tabMainWidget->setDocumentMode(false);
        tabMainWidget->setTabsClosable(false);
        tabExplore = new QWidget();
        tabExplore->setObjectName(QStringLiteral("tabExplore"));
        horizontalLayout_2 = new QHBoxLayout(tabExplore);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        vLayout1 = new QVBoxLayout();
        vLayout1->setObjectName(QStringLiteral("vLayout1"));
        grpMain = new QGroupBox(tabExplore);
        grpMain->setObjectName(QStringLiteral("grpMain"));
        horizontalLayout_6 = new QHBoxLayout(grpMain);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        grpHotMixes = new QGroupBox(grpMain);
        grpHotMixes->setObjectName(QStringLiteral("grpHotMixes"));
        horizontalLayout_9 = new QHBoxLayout(grpHotMixes);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        widgHotMixes = new QWidget(grpHotMixes);
        widgHotMixes->setObjectName(QStringLiteral("widgHotMixes"));

        horizontalLayout_9->addWidget(widgHotMixes);


        gridLayout_2->addWidget(grpHotMixes, 3, 0, 1, 1);

        grpExplore = new QGroupBox(grpMain);
        grpExplore->setObjectName(QStringLiteral("grpExplore"));
        horizontalLayout_7 = new QHBoxLayout(grpExplore);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        vLayout2 = new QVBoxLayout();
        vLayout2->setObjectName(QStringLiteral("vLayout2"));
        widgExplore = new QWidget(grpExplore);
        widgExplore->setObjectName(QStringLiteral("widgExplore"));

        vLayout2->addWidget(widgExplore);

        hLayout1 = new QHBoxLayout();
        hLayout1->setObjectName(QStringLiteral("hLayout1"));
        hLayout1->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnExplore = new QPushButton(grpExplore);
        btnExplore->setObjectName(QStringLiteral("btnExplore"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        btnExplore->setFont(font);
        btnExplore->setAutoFillBackground(false);

        hLayout1->addWidget(btnExplore);


        vLayout2->addLayout(hLayout1);


        horizontalLayout_7->addLayout(vLayout2);


        gridLayout_2->addWidget(grpExplore, 0, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_2);


        vLayout1->addWidget(grpMain);


        horizontalLayout_2->addLayout(vLayout1);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/Resources/img_src/arrow_switch.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMainWidget->addTab(tabExplore, icon4, QString());
        tabSearch = new QWidget();
        tabSearch->setObjectName(QStringLiteral("tabSearch"));
        horizontalLayout_4 = new QHBoxLayout(tabSearch);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(tabSearch);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(200, 16777215));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lblSearch = new QLabel(groupBox);
        lblSearch->setObjectName(QStringLiteral("lblSearch"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblSearch);

        txtSearch = new QLineEdit(groupBox);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtSearch);

        lblOrder = new QLabel(groupBox);
        lblOrder->setObjectName(QStringLiteral("lblOrder"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblOrder);

        cmbOrder = new QComboBox(groupBox);
        cmbOrder->setObjectName(QStringLiteral("cmbOrder"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cmbOrder);

        btnSearch = new QPushButton(groupBox);
        btnSearch->setObjectName(QStringLiteral("btnSearch"));
        btnSearch->setText(QStringLiteral("Search"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, btnSearch);

        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(2, QFormLayout::SpanningRole, verticalSpacer);


        horizontalLayout_5->addLayout(formLayout);


        horizontalLayout_3->addWidget(groupBox);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        grpSearchMixes = new QGroupBox(tabSearch);
        grpSearchMixes->setObjectName(QStringLiteral("grpSearchMixes"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(grpSearchMixes->sizePolicy().hasHeightForWidth());
        grpSearchMixes->setSizePolicy(sizePolicy2);
        grpSearchMixes->setMinimumSize(QSize(550, 0));
        horizontalLayout_10 = new QHBoxLayout(grpSearchMixes);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        grdSearchMixes = new QGridLayout();
        grdSearchMixes->setObjectName(QStringLiteral("grdSearchMixes"));

        horizontalLayout_10->addLayout(grdSearchMixes);


        gridLayout->addWidget(grpSearchMixes, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/Resources/img_src/google_custom_search.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabMainWidget->addTab(tabSearch, icon5, QString());

        horizontalLayout->addWidget(tabMainWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionExplorer);
        toolBar->addAction(actionEn_cours);
        toolBar->addAction(actionProfil);
        toolBar->addAction(actionQuitter);

        retranslateUi(MainWindow);

        tabMainWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "8player", 0));
        actionExplorer->setText(QApplication::translate("MainWindow", "Explore", 0));
#ifndef QT_NO_TOOLTIP
        actionExplorer->setToolTip(QApplication::translate("MainWindow", "Explorer de la musiuqe", 0));
#endif // QT_NO_TOOLTIP
        actionProfil->setText(QApplication::translate("MainWindow", "Profile", 0));
#ifndef QT_NO_TOOLTIP
        actionProfil->setToolTip(QApplication::translate("MainWindow", "Voir votre profil", 0));
#endif // QT_NO_TOOLTIP
        actionQuitter->setText(QApplication::translate("MainWindow", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionQuitter->setToolTip(QApplication::translate("MainWindow", "Quitter le programe", 0));
#endif // QT_NO_TOOLTIP
        actionEn_cours->setText(QApplication::translate("MainWindow", "Listening", 0));
#ifndef QT_NO_TOOLTIP
        actionEn_cours->setToolTip(QApplication::translate("MainWindow", "\303\211coute en cours", 0));
#endif // QT_NO_TOOLTIP
        grpMain->setTitle(QApplication::translate("MainWindow", "8player", 0));
        grpHotMixes->setTitle(QApplication::translate("MainWindow", "Hot Mixes Right now ...", 0));
        grpExplore->setTitle(QApplication::translate("MainWindow", "Explore Music ...", 0));
        btnExplore->setText(QApplication::translate("MainWindow", "Explore", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabExplore), QApplication::translate("MainWindow", "Explore", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Recherche", 0));
        lblSearch->setText(QApplication::translate("MainWindow", "Search", 0));
        lblOrder->setText(QApplication::translate("MainWindow", "Order", 0));
        cmbOrder->clear();
        cmbOrder->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Most recent", 0)
         << QApplication::translate("MainWindow", "Popularity", 0)
         << QApplication::translate("MainWindow", "Hot", 0)
        );
        cmbOrder->setCurrentText(QApplication::translate("MainWindow", "Most recent", 0));
        grpSearchMixes->setTitle(QApplication::translate("MainWindow", "Search Results", 0));
        tabMainWidget->setTabText(tabMainWidget->indexOf(tabSearch), QApplication::translate("MainWindow", "Search", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
