/********************************************************************************
** Form generated from reading UI file 'CurrentlyPlaying.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTLYPLAYING_H
#define UI_CURRENTLYPLAYING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_currentlyListen
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *grpCurrentplyPlaying;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lblMixImg;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblMixName;
    QLabel *lblDescription;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblReleaseName;
    QLabel *lblName;
    QLabel *lblPerformer;
    QLabel *lblYear;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnProfile;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnPlayPause;
    QPushButton *btnSkip;
    QProgressBar *prgListenStatus;
    QSlider *volumeSlider;

    void setupUi(QWidget *currentlyListen)
    {
        if (currentlyListen->objectName().isEmpty())
            currentlyListen->setObjectName(QStringLiteral("currentlyListen"));
        currentlyListen->resize(545, 401);
        horizontalLayout = new QHBoxLayout(currentlyListen);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        grpCurrentplyPlaying = new QGroupBox(currentlyListen);
        grpCurrentplyPlaying->setObjectName(QStringLiteral("grpCurrentplyPlaying"));
        horizontalLayout_2 = new QHBoxLayout(grpCurrentplyPlaying);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lblMixImg = new QLabel(grpCurrentplyPlaying);
        lblMixImg->setObjectName(QStringLiteral("lblMixImg"));
        lblMixImg->setMinimumSize(QSize(200, 200));
        lblMixImg->setMaximumSize(QSize(200, 200));
        lblMixImg->setStyleSheet(QStringLiteral("border: 1px solid #333;"));
        lblMixImg->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lblMixImg);

        horizontalSpacer = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblMixName = new QLabel(grpCurrentplyPlaying);
        lblMixName->setObjectName(QStringLiteral("lblMixName"));
        lblMixName->setMaximumSize(QSize(16777215, 36));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lblMixName->setFont(font);

        verticalLayout_2->addWidget(lblMixName);

        lblDescription = new QLabel(grpCurrentplyPlaying);
        lblDescription->setObjectName(QStringLiteral("lblDescription"));
        lblDescription->setMaximumSize(QSize(300, 16777215));
        lblDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblDescription->setWordWrap(true);

        verticalLayout_2->addWidget(lblDescription);

        groupBox = new QGroupBox(grpCurrentplyPlaying);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(300, 300));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lblReleaseName = new QLabel(groupBox);
        lblReleaseName->setObjectName(QStringLiteral("lblReleaseName"));

        verticalLayout_3->addWidget(lblReleaseName);

        lblName = new QLabel(groupBox);
        lblName->setObjectName(QStringLiteral("lblName"));

        verticalLayout_3->addWidget(lblName);

        lblPerformer = new QLabel(groupBox);
        lblPerformer->setObjectName(QStringLiteral("lblPerformer"));

        verticalLayout_3->addWidget(lblPerformer);

        lblYear = new QLabel(groupBox);
        lblYear->setObjectName(QStringLiteral("lblYear"));

        verticalLayout_3->addWidget(lblYear);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_2->addWidget(groupBox);

        widget_2 = new QWidget(grpCurrentplyPlaying);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        btnProfile = new QPushButton(widget_2);
        btnProfile->setObjectName(QStringLiteral("btnProfile"));

        horizontalLayout_6->addWidget(btnProfile);


        horizontalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_2->addWidget(widget_2);


        horizontalLayout_7->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_7);

        widget = new QWidget(grpCurrentplyPlaying);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        btnPlayPause = new QPushButton(widget);
        btnPlayPause->setObjectName(QStringLiteral("btnPlayPause"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/Resources/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlayPause->setIcon(icon);
        btnPlayPause->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(btnPlayPause);

        btnSkip = new QPushButton(widget);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/Resources/Gnome-Media-Skip-Forward-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkip->setIcon(icon1);
        btnSkip->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(btnSkip);

        prgListenStatus = new QProgressBar(widget);
        prgListenStatus->setObjectName(QStringLiteral("prgListenStatus"));
        prgListenStatus->setMinimumSize(QSize(0, 32));
        prgListenStatus->setMaximumSize(QSize(16777215, 32));
        prgListenStatus->setBaseSize(QSize(0, 32));
        prgListenStatus->setValue(0);
        prgListenStatus->setTextVisible(true);
        prgListenStatus->setInvertedAppearance(false);

        horizontalLayout_3->addWidget(prgListenStatus);

        volumeSlider = new QSlider(widget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMinimumSize(QSize(50, 25));
        volumeSlider->setMaximumSize(QSize(100, 25));
        volumeSlider->setBaseSize(QSize(50, 25));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(volumeSlider);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(grpCurrentplyPlaying);


        retranslateUi(currentlyListen);

        QMetaObject::connectSlotsByName(currentlyListen);
    } // setupUi

    void retranslateUi(QWidget *currentlyListen)
    {
        currentlyListen->setWindowTitle(QApplication::translate("currentlyListen", "Currently Playing Mix", 0));
        grpCurrentplyPlaying->setTitle(QApplication::translate("currentlyListen", "Currently Playing Mix", 0));
        lblMixImg->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        lblMixName->setText(QApplication::translate("currentlyListen", "Nom du Mix", 0));
        lblDescription->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        groupBox->setTitle(QApplication::translate("currentlyListen", "Currently Playing ...", 0));
        lblReleaseName->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        lblName->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        lblPerformer->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        lblYear->setText(QApplication::translate("currentlyListen", "TextLabel", 0));
        btnProfile->setText(QApplication::translate("currentlyListen", "Slug Utilisateur", 0));
        btnPlayPause->setText(QString());
        btnSkip->setText(QString());
        prgListenStatus->setFormat(QApplication::translate("currentlyListen", "%v s", 0));
    } // retranslateUi

};

namespace Ui {
    class currentlyListen: public Ui_currentlyListen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTLYPLAYING_H
