/********************************************************************************
** Form generated from reading UI file 'xxxx.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XXXX_H
#define UI_XXXX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XXXXClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *recvLabel;
    QTextEdit *m_recvTextEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *sendLabel;
    QTextEdit *m_sendTextEdit;
    QVBoxLayout *verticalLayout;
    QComboBox *m_comboBox;
    QComboBox *m_itemComboBox;
    QComboBox *m_parityComboBox;
    QPushButton *m_pushButton;
    QCheckBox *m_timerCheckBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *XXXXClass)
    {
        if (XXXXClass->objectName().isEmpty())
            XXXXClass->setObjectName(QStringLiteral("XXXXClass"));
        XXXXClass->resize(600, 400);
        centralWidget = new QWidget(XXXXClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        recvLabel = new QLabel(centralWidget);
        recvLabel->setObjectName(QStringLiteral("recvLabel"));

        verticalLayout_2->addWidget(recvLabel);

        m_recvTextEdit = new QTextEdit(centralWidget);
        m_recvTextEdit->setObjectName(QStringLiteral("m_recvTextEdit"));

        verticalLayout_2->addWidget(m_recvTextEdit);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sendLabel = new QLabel(centralWidget);
        sendLabel->setObjectName(QStringLiteral("sendLabel"));

        verticalLayout_3->addWidget(sendLabel);

        m_sendTextEdit = new QTextEdit(centralWidget);
        m_sendTextEdit->setObjectName(QStringLiteral("m_sendTextEdit"));

        verticalLayout_3->addWidget(m_sendTextEdit);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_comboBox = new QComboBox(centralWidget);
        m_comboBox->setObjectName(QStringLiteral("m_comboBox"));

        verticalLayout->addWidget(m_comboBox);

        m_itemComboBox = new QComboBox(centralWidget);
        m_itemComboBox->setObjectName(QStringLiteral("m_itemComboBox"));

        verticalLayout->addWidget(m_itemComboBox);

        m_parityComboBox = new QComboBox(centralWidget);
        m_parityComboBox->setObjectName(QStringLiteral("m_parityComboBox"));

        verticalLayout->addWidget(m_parityComboBox);

        m_pushButton = new QPushButton(centralWidget);
        m_pushButton->setObjectName(QStringLiteral("m_pushButton"));

        verticalLayout->addWidget(m_pushButton);

        m_timerCheckBox = new QCheckBox(centralWidget);
        m_timerCheckBox->setObjectName(QStringLiteral("m_timerCheckBox"));

        verticalLayout->addWidget(m_timerCheckBox);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        XXXXClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(XXXXClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        XXXXClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(XXXXClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        XXXXClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(XXXXClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        XXXXClass->setStatusBar(statusBar);

        retranslateUi(XXXXClass);

        QMetaObject::connectSlotsByName(XXXXClass);
    } // setupUi

    void retranslateUi(QMainWindow *XXXXClass)
    {
        XXXXClass->setWindowTitle(QApplication::translate("XXXXClass", "XXXX", 0));
        recvLabel->setText(QApplication::translate("XXXXClass", "RECV", 0));
        sendLabel->setText(QApplication::translate("XXXXClass", "SEND", 0));
        m_pushButton->setText(QApplication::translate("XXXXClass", "\345\217\221\351\200\201", 0));
        m_timerCheckBox->setText(QApplication::translate("XXXXClass", "\345\256\232\346\227\266\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class XXXXClass: public Ui_XXXXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XXXX_H
