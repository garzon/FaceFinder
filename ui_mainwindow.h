/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *textInput;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *textOutput;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *textJump;
    QLabel *label_4;
    QLineEdit *textWidth;
    QLabel *label_5;
    QLineEdit *textHeight;
    QPushButton *btnProcess;
    QHBoxLayout *horizontalLayout_4;
    QProgressBar *progressBar;
    QLabel *lblVideo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(591, 618);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 571, 531));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        textInput = new QLineEdit(verticalLayoutWidget);
        textInput->setObjectName(QStringLiteral("textInput"));

        horizontalLayout->addWidget(textInput);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        textOutput = new QLineEdit(verticalLayoutWidget);
        textOutput->setObjectName(QStringLiteral("textOutput"));

        horizontalLayout_2->addWidget(textOutput);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        textJump = new QLineEdit(verticalLayoutWidget);
        textJump->setObjectName(QStringLiteral("textJump"));

        horizontalLayout_3->addWidget(textJump);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        textWidth = new QLineEdit(verticalLayoutWidget);
        textWidth->setObjectName(QStringLiteral("textWidth"));

        horizontalLayout_3->addWidget(textWidth);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        textHeight = new QLineEdit(verticalLayoutWidget);
        textHeight->setObjectName(QStringLiteral("textHeight"));

        horizontalLayout_3->addWidget(textHeight);

        btnProcess = new QPushButton(verticalLayoutWidget);
        btnProcess->setObjectName(QStringLiteral("btnProcess"));

        horizontalLayout_3->addWidget(btnProcess);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_4->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_4);

        lblVideo = new QLabel(verticalLayoutWidget);
        lblVideo->setObjectName(QStringLiteral("lblVideo"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblVideo->sizePolicy().hasHeightForWidth());
        lblVideo->setSizePolicy(sizePolicy);
        lblVideo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblVideo);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(outputDir()));
        QObject::connect(btnProcess, SIGNAL(clicked()), MainWindow, SLOT(process()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(inputFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Input AVI:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Browse", 0));
        label_2->setText(QApplication::translate("MainWindow", "Output DIR:", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Browse", 0));
        label_3->setText(QApplication::translate("MainWindow", "Jump Step", 0));
        textJump->setText(QApplication::translate("MainWindow", "5", 0));
        label_4->setText(QApplication::translate("MainWindow", "Resize:", 0));
        textWidth->setText(QApplication::translate("MainWindow", "50", 0));
        label_5->setText(QApplication::translate("MainWindow", "x", 0));
        textHeight->setText(QApplication::translate("MainWindow", "50", 0));
        btnProcess->setText(QApplication::translate("MainWindow", "Process", 0));
        lblVideo->setText(QApplication::translate("MainWindow", "None", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
