/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <animationlogin.h>
#include "clineedit.h"

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout_8;
    animationLogin *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QWidget *widgetWinTitle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelWinIcon;
    QLabel *labelWinTitle;
    QPushButton *btnWinMenu;
    QPushButton *btnWinMin;
    QPushButton *btnWinClose;
    QWidget *widgetBody;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelUserHead;
    QVBoxLayout *verticalLayout;
    QIconLineEdit *lineEditUser;
    QIconLineEdit *lineEditPasswed;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxPasswd;
    QCheckBox *checkBoxAutoLogin;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnLogin;
    QPushButton *btnRegedit;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *widgetWinTitle_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelWinTitle_2;
    QPushButton *btnWinMin_2;
    QPushButton *btnWinClose_2;
    QWidget *widgetBody_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout;
    QLabel *label_5;
    QIPLineEdit *lineEditHostAddr;
    QLabel *label_6;
    QLineEdit *lineEditHostMsgPort;
    QLabel *label_7;
    QLineEdit *lineEditHostFilePort;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSaveCfg;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName(QString::fromUtf8("LoginWidget"));
        LoginWidget->resize(410, 383);
        LoginWidget->setStyleSheet(QString::fromUtf8("QWidget#page,QWidget#page_2{\n"
"border:1px solid #A5A6A8;\n"
"border-radius:4px;\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(LoginWidget);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(20, 50, 20, 50);
        stackedWidget = new animationLogin(LoginWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        widgetWinTitle = new QWidget(page);
        widgetWinTitle->setObjectName(QString::fromUtf8("widgetWinTitle"));
        horizontalLayout_3 = new QHBoxLayout(widgetWinTitle);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelWinIcon = new QLabel(widgetWinTitle);
        labelWinIcon->setObjectName(QString::fromUtf8("labelWinIcon"));
        labelWinIcon->setPixmap(QPixmap(QString::fromUtf8(":/resource/images/robot.png")));
        labelWinIcon->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labelWinIcon);

        labelWinTitle = new QLabel(widgetWinTitle);
        labelWinTitle->setObjectName(QString::fromUtf8("labelWinTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelWinTitle->sizePolicy().hasHeightForWidth());
        labelWinTitle->setSizePolicy(sizePolicy);
        labelWinTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelWinTitle);

        btnWinMenu = new QPushButton(widgetWinTitle);
        btnWinMenu->setObjectName(QString::fromUtf8("btnWinMenu"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/common/ic_login_cfg.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinMenu->setIcon(icon);

        horizontalLayout_3->addWidget(btnWinMenu);

        btnWinMin = new QPushButton(widgetWinTitle);
        btnWinMin->setObjectName(QString::fromUtf8("btnWinMin"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/common/ic_min.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinMin->setIcon(icon1);

        horizontalLayout_3->addWidget(btnWinMin);

        btnWinClose = new QPushButton(widgetWinTitle);
        btnWinClose->setObjectName(QString::fromUtf8("btnWinClose"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/common/ic_close_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWinClose->setIcon(icon2);

        horizontalLayout_3->addWidget(btnWinClose);


        verticalLayout_5->addWidget(widgetWinTitle);

        widgetBody = new QWidget(page);
        widgetBody->setObjectName(QString::fromUtf8("widgetBody"));
        verticalLayout_3 = new QVBoxLayout(widgetBody);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widgetBody);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resource/background/logo.jpg")));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(40, 20, 40, 20);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        labelUserHead = new QLabel(widgetBody);
        labelUserHead->setObjectName(QString::fromUtf8("labelUserHead"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelUserHead->sizePolicy().hasHeightForWidth());
        labelUserHead->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(false);
        font.setKerning(true);
        labelUserHead->setFont(font);
        labelUserHead->setStyleSheet(QString::fromUtf8("border:1px solid #C9C9C9;\n"
"padding-left:10px;\n"
"padding-right:10px;\n"
"border-radius:4px;\n"
"\n"
"\n"
""));
        labelUserHead->setPixmap(QPixmap(QString::fromUtf8(":/resource/head/head-64.png")));
        labelUserHead->setAlignment(Qt::AlignCenter);
        labelUserHead->setWordWrap(false);
        labelUserHead->setIndent(-1);

        horizontalLayout_2->addWidget(labelUserHead);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEditUser = new QIconLineEdit(widgetBody);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        verticalLayout->addWidget(lineEditUser);

        lineEditPasswed = new QIconLineEdit(widgetBody);
        lineEditPasswed->setObjectName(QString::fromUtf8("lineEditPasswed"));

        verticalLayout->addWidget(lineEditPasswed);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBoxPasswd = new QCheckBox(widgetBody);
        checkBoxPasswd->setObjectName(QString::fromUtf8("checkBoxPasswd"));

        horizontalLayout->addWidget(checkBoxPasswd);

        checkBoxAutoLogin = new QCheckBox(widgetBody);
        checkBoxAutoLogin->setObjectName(QString::fromUtf8("checkBoxAutoLogin"));

        horizontalLayout->addWidget(checkBoxAutoLogin);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(30);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(10, 5, 10, 5);
        btnLogin = new QPushButton(widgetBody);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));

        horizontalLayout_8->addWidget(btnLogin);

        btnRegedit = new QPushButton(widgetBody);
        btnRegedit->setObjectName(QString::fromUtf8("btnRegedit"));

        horizontalLayout_8->addWidget(btnRegedit);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_5->addWidget(widgetBody);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetWinTitle_2 = new QWidget(page_2);
        widgetWinTitle_2->setObjectName(QString::fromUtf8("widgetWinTitle_2"));
        widgetWinTitle_2->setMinimumSize(QSize(0, 30));
        widgetWinTitle_2->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_5 = new QHBoxLayout(widgetWinTitle_2);
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(10, 0, 0, 0);
        labelWinTitle_2 = new QLabel(widgetWinTitle_2);
        labelWinTitle_2->setObjectName(QString::fromUtf8("labelWinTitle_2"));
        labelWinTitle_2->setStyleSheet(QString::fromUtf8("color: #FFFFFF;"));

        horizontalLayout_5->addWidget(labelWinTitle_2);

        btnWinMin_2 = new QPushButton(widgetWinTitle_2);
        btnWinMin_2->setObjectName(QString::fromUtf8("btnWinMin_2"));
        btnWinMin_2->setFocusPolicy(Qt::NoFocus);
        btnWinMin_2->setIcon(icon1);

        horizontalLayout_5->addWidget(btnWinMin_2);

        btnWinClose_2 = new QPushButton(widgetWinTitle_2);
        btnWinClose_2->setObjectName(QString::fromUtf8("btnWinClose_2"));
        btnWinClose_2->setFocusPolicy(Qt::NoFocus);
        btnWinClose_2->setIcon(icon2);

        horizontalLayout_5->addWidget(btnWinClose_2);

        horizontalLayout_5->setStretch(0, 1);

        verticalLayout_4->addWidget(widgetWinTitle_2);

        widgetBody_2 = new QWidget(page_2);
        widgetBody_2->setObjectName(QString::fromUtf8("widgetBody_2"));
        verticalLayout_6 = new QVBoxLayout(widgetBody_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox = new QGroupBox(widgetBody_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 0, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        lineEditHostAddr = new QIPLineEdit(groupBox);
        lineEditHostAddr->setObjectName(QString::fromUtf8("lineEditHostAddr"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditHostAddr);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        lineEditHostMsgPort = new QLineEdit(groupBox);
        lineEditHostMsgPort->setObjectName(QString::fromUtf8("lineEditHostMsgPort"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditHostMsgPort);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        lineEditHostFilePort = new QLineEdit(groupBox);
        lineEditHostFilePort->setObjectName(QString::fromUtf8("lineEditHostFilePort"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditHostFilePort);


        horizontalLayout_6->addLayout(formLayout);


        verticalLayout_7->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout_6->addWidget(groupBox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        btnCancel = new QPushButton(widgetBody_2);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_7->addWidget(btnCancel);

        btnSaveCfg = new QPushButton(widgetBody_2);
        btnSaveCfg->setObjectName(QString::fromUtf8("btnSaveCfg"));

        horizontalLayout_7->addWidget(btnSaveCfg);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(widgetBody_2);

        stackedWidget->addWidget(page_2);

        verticalLayout_8->addWidget(stackedWidget);


        retranslateUi(LoginWidget);
        QObject::connect(btnWinClose, SIGNAL(clicked()), LoginWidget, SLOT(close()));
        QObject::connect(btnWinClose_2, SIGNAL(clicked()), LoginWidget, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        labelWinIcon->setText(QString());
        labelWinTitle->setText(QString());
        btnWinMenu->setText(QString());
        btnWinMin->setText(QString());
        btnWinClose->setText(QString());
        label_3->setText(QString());
        labelUserHead->setText(QString());
        checkBoxPasswd->setText(QCoreApplication::translate("LoginWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        checkBoxAutoLogin->setText(QCoreApplication::translate("LoginWidget", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225", nullptr));
        btnRegedit->setText(QCoreApplication::translate("LoginWidget", "\346\263\250\345\206\214", nullptr));
        labelWinTitle_2->setText(QCoreApplication::translate("LoginWidget", "\347\231\273\345\275\225\351\205\215\347\275\256", nullptr));
        btnWinMin_2->setText(QString());
        btnWinClose_2->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("LoginWidget", "\346\234\215\345\212\241\345\231\250\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("LoginWidget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200\351\205\215\347\275\256\357\274\232", nullptr));
        lineEditHostAddr->setText(QCoreApplication::translate("LoginWidget", "192.168.0.103", nullptr));
        label_6->setText(QCoreApplication::translate("LoginWidget", "\346\266\210\346\201\257\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEditHostMsgPort->setText(QCoreApplication::translate("LoginWidget", "60100", nullptr));
        label_7->setText(QCoreApplication::translate("LoginWidget", "\346\226\207\344\273\266\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", nullptr));
        lineEditHostFilePort->setText(QCoreApplication::translate("LoginWidget", "60101", nullptr));
        btnCancel->setText(QCoreApplication::translate("LoginWidget", "\345\217\226\346\266\210", nullptr));
        btnSaveCfg->setText(QCoreApplication::translate("LoginWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
