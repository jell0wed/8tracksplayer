/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLineEdit *txtUsername;
    QLineEdit *txtPassword;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLogin;
    QLabel *lblLogo;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->setWindowModality(Qt::ApplicationModal);
        LoginDialog->resize(488, 299);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginDialog->sizePolicy().hasHeightForWidth());
        LoginDialog->setSizePolicy(sizePolicy);
        LoginDialog->setBaseSize(QSize(0, 0));
        LoginDialog->setMouseTracking(false);
        LoginDialog->setFocusPolicy(Qt::NoFocus);
        LoginDialog->setStyleSheet(QLatin1String("QDialog#LoginDialog {\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(11, 54, 86, 255), stop:1 rgba(0, 25, 61, 255));\n"
"\n"
"}"));
        LoginDialog->setSizeGripEnabled(false);
        LoginDialog->setModal(false);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        txtUsername = new QLineEdit(LoginDialog);
        txtUsername->setObjectName(QStringLiteral("txtUsername"));
        txtUsername->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"border:1px solid #c9c9c9;\n"
"background-color: #ffffff;\n"
"min-height:28px;\n"
"background-image: url(:/lineEdit/img_src/qlineedit_bg.jpg);\n"
"background-repeat: repeat-x;\n"
"	font: 75 11pt \"Myriad Pro\";\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border :1px solid #0073af;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, txtUsername);

        txtPassword = new QLineEdit(LoginDialog);
        txtPassword->setObjectName(QStringLiteral("txtPassword"));
        txtPassword->setStyleSheet(QLatin1String("QLineEdit\n"
"{\n"
"border:1px solid #c9c9c9;\n"
"background-color: #ffffff;\n"
"min-height:28px;\n"
"background-image: url(:/lineEdit/img_src/qlineedit_bg.jpg);\n"
"background-repeat: repeat-x;\n"
"	font: 75 11pt \"Myriad Pro\";\n"
"}\n"
"\n"
"QLineEdit:focus\n"
"{\n"
"	border :1px solid #0073af;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, txtPassword);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer);

        btnLogin = new QPushButton(LoginDialog);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        btnLogin->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(217, 217, 217, 255));\n"
"border:none;\n"
"border-radius:5px;\n"
"font: 75 10pt \"Myriad Pro\";\n"
"font-weight: 700;\n"
"color: rgb(72, 72, 72);\n"
"min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(217, 217, 217, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
""));

        formLayout->setWidget(4, QFormLayout::FieldRole, btnLogin);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        lblLogo = new QLabel(LoginDialog);
        lblLogo->setObjectName(QStringLiteral("lblLogo"));
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/logo/Resources/8tracks.png")));

        gridLayout->addWidget(lblLogo, 0, 1, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "8player - Authentification", 0));
        txtUsername->setText(QApplication::translate("LoginDialog", "jell0wed", 0));
        txtUsername->setPlaceholderText(QApplication::translate("LoginDialog", "Enter your username !", 0));
        txtPassword->setText(QString());
        txtPassword->setPlaceholderText(QApplication::translate("LoginDialog", "***********", 0));
        btnLogin->setText(QApplication::translate("LoginDialog", "Authentification", 0));
        lblLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
