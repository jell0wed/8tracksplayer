/********************************************************************************
** Form generated from reading UI file 'ProfileView.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEVIEW_H
#define UI_PROFILEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileView
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *grpProfile;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblAvatar200;
    QVBoxLayout *verticalLayout;
    QLabel *lblSlug;
    QLabel *lblBio;
    QLabel *lblLocation;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;

    void setupUi(QWidget *ProfileView)
    {
        if (ProfileView->objectName().isEmpty())
            ProfileView->setObjectName(QStringLiteral("ProfileView"));
        ProfileView->resize(594, 253);
        horizontalLayout = new QHBoxLayout(ProfileView);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        grpProfile = new QGroupBox(ProfileView);
        grpProfile->setObjectName(QStringLiteral("grpProfile"));
        horizontalLayout_2 = new QHBoxLayout(grpProfile);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        lblAvatar200 = new QLabel(grpProfile);
        lblAvatar200->setObjectName(QStringLiteral("lblAvatar200"));
        lblAvatar200->setMinimumSize(QSize(200, 200));
        lblAvatar200->setMaximumSize(QSize(200, 200));
        lblAvatar200->setBaseSize(QSize(200, 200));
        lblAvatar200->setStyleSheet(QStringLiteral("border:1px solid #000"));
        lblAvatar200->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_3->addWidget(lblAvatar200);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lblSlug = new QLabel(grpProfile);
        lblSlug->setObjectName(QStringLiteral("lblSlug"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        lblSlug->setFont(font);
        lblSlug->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(lblSlug);

        lblBio = new QLabel(grpProfile);
        lblBio->setObjectName(QStringLiteral("lblBio"));
        lblBio->setWordWrap(true);

        verticalLayout->addWidget(lblBio);

        lblLocation = new QLabel(grpProfile);
        lblLocation->setObjectName(QStringLiteral("lblLocation"));

        verticalLayout->addWidget(lblLocation);

        widget = new QWidget(grpProfile);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(widget);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(grpProfile);


        retranslateUi(ProfileView);

        QMetaObject::connectSlotsByName(ProfileView);
    } // setupUi

    void retranslateUi(QWidget *ProfileView)
    {
        ProfileView->setWindowTitle(QApplication::translate("ProfileView", "Profile View", 0));
        grpProfile->setTitle(QApplication::translate("ProfileView", "Profile", 0));
        lblAvatar200->setText(QString());
        lblSlug->setText(QString());
        lblBio->setText(QString());
        lblLocation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProfileView: public Ui_ProfileView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEVIEW_H
