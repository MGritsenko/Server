/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStartServer;
    QAction *actionStopServer;
    QAction *actionExit;
    QAction *actionClientsList;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *frameWindow;
    QLabel *alphaWindow;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *clientsListLayout;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QWidget *fromColor;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *blueFromValLabel;
    QSlider *blueFromSlider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *greenFromValLabel;
    QSlider *greenFromSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *redFromValLabel;
    QSlider *redFromSlider;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QWidget *toColor;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLabel *blueToValLabel;
    QSlider *blueToSlider;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLabel *greenToValLabel;
    QSlider *greenToSlider;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLabel *redToValLabel;
    QSlider *redToSlider;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *clientsBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *commandsBox;
    QPushButton *sendButton;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuNetwork;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1076, 767);
        actionStartServer = new QAction(MainWindow);
        actionStartServer->setObjectName(QString::fromUtf8("actionStartServer"));
        actionStopServer = new QAction(MainWindow);
        actionStopServer->setObjectName(QString::fromUtf8("actionStopServer"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionClientsList = new QAction(MainWindow);
        actionClientsList->setObjectName(QString::fromUtf8("actionClientsList"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        frameWindow = new QLabel(centralwidget);
        frameWindow->setObjectName(QString::fromUtf8("frameWindow"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameWindow->sizePolicy().hasHeightForWidth());
        frameWindow->setSizePolicy(sizePolicy);
        frameWindow->setFrameShape(QFrame::Box);
        frameWindow->setFrameShadow(QFrame::Plain);

        horizontalLayout_2->addWidget(frameWindow);

        alphaWindow = new QLabel(centralwidget);
        alphaWindow->setObjectName(QString::fromUtf8("alphaWindow"));
        sizePolicy.setHeightForWidth(alphaWindow->sizePolicy().hasHeightForWidth());
        alphaWindow->setSizePolicy(sizePolicy);
        alphaWindow->setMinimumSize(QSize(0, 320));
        alphaWindow->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(alphaWindow);


        verticalLayout_8->addLayout(horizontalLayout_2);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        clientsListLayout = new QHBoxLayout();
        clientsListLayout->setObjectName(QString::fromUtf8("clientsListLayout"));

        verticalLayout_5->addLayout(clientsListLayout);


        horizontalLayout_17->addLayout(verticalLayout_5);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_17->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setWordWrap(true);

        horizontalLayout_9->addWidget(label_8);

        fromColor = new QWidget(centralwidget);
        fromColor->setObjectName(QString::fromUtf8("fromColor"));

        horizontalLayout_9->addWidget(fromColor);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        blueFromValLabel = new QLabel(centralwidget);
        blueFromValLabel->setObjectName(QString::fromUtf8("blueFromValLabel"));

        horizontalLayout_8->addWidget(blueFromValLabel);

        blueFromSlider = new QSlider(centralwidget);
        blueFromSlider->setObjectName(QString::fromUtf8("blueFromSlider"));
        blueFromSlider->setMaximum(255);
        blueFromSlider->setPageStep(1);
        blueFromSlider->setValue(0);
        blueFromSlider->setOrientation(Qt::Horizontal);
        blueFromSlider->setTickInterval(1);

        horizontalLayout_8->addWidget(blueFromSlider);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        greenFromValLabel = new QLabel(centralwidget);
        greenFromValLabel->setObjectName(QString::fromUtf8("greenFromValLabel"));

        horizontalLayout_7->addWidget(greenFromValLabel);

        greenFromSlider = new QSlider(centralwidget);
        greenFromSlider->setObjectName(QString::fromUtf8("greenFromSlider"));
        greenFromSlider->setMaximum(255);
        greenFromSlider->setPageStep(1);
        greenFromSlider->setValue(0);
        greenFromSlider->setOrientation(Qt::Horizontal);
        greenFromSlider->setTickInterval(1);

        horizontalLayout_7->addWidget(greenFromSlider);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        redFromValLabel = new QLabel(centralwidget);
        redFromValLabel->setObjectName(QString::fromUtf8("redFromValLabel"));

        horizontalLayout_6->addWidget(redFromValLabel);

        redFromSlider = new QSlider(centralwidget);
        redFromSlider->setObjectName(QString::fromUtf8("redFromSlider"));
        redFromSlider->setMaximum(255);
        redFromSlider->setPageStep(1);
        redFromSlider->setValue(255);
        redFromSlider->setOrientation(Qt::Horizontal);
        redFromSlider->setTickInterval(1);

        horizontalLayout_6->addWidget(redFromSlider);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setWordWrap(true);

        horizontalLayout_10->addWidget(label_9);

        toColor = new QWidget(centralwidget);
        toColor->setObjectName(QString::fromUtf8("toColor"));

        horizontalLayout_10->addWidget(toColor);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        blueToValLabel = new QLabel(centralwidget);
        blueToValLabel->setObjectName(QString::fromUtf8("blueToValLabel"));

        horizontalLayout_11->addWidget(blueToValLabel);

        blueToSlider = new QSlider(centralwidget);
        blueToSlider->setObjectName(QString::fromUtf8("blueToSlider"));
        blueToSlider->setMaximum(255);
        blueToSlider->setPageStep(1);
        blueToSlider->setValue(215);
        blueToSlider->setOrientation(Qt::Horizontal);
        blueToSlider->setTickInterval(1);

        horizontalLayout_11->addWidget(blueToSlider);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        greenToValLabel = new QLabel(centralwidget);
        greenToValLabel->setObjectName(QString::fromUtf8("greenToValLabel"));

        horizontalLayout_12->addWidget(greenToValLabel);

        greenToSlider = new QSlider(centralwidget);
        greenToSlider->setObjectName(QString::fromUtf8("greenToSlider"));
        greenToSlider->setMaximum(255);
        greenToSlider->setPageStep(1);
        greenToSlider->setValue(120);
        greenToSlider->setOrientation(Qt::Horizontal);
        greenToSlider->setTickInterval(1);

        horizontalLayout_12->addWidget(greenToSlider);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        redToValLabel = new QLabel(centralwidget);
        redToValLabel->setObjectName(QString::fromUtf8("redToValLabel"));

        horizontalLayout_13->addWidget(redToValLabel);

        redToSlider = new QSlider(centralwidget);
        redToSlider->setObjectName(QString::fromUtf8("redToSlider"));
        redToSlider->setMaximum(255);
        redToSlider->setPageStep(1);
        redToSlider->setValue(255);
        redToSlider->setOrientation(Qt::Horizontal);
        redToSlider->setTickInterval(1);

        horizontalLayout_13->addWidget(redToSlider);


        verticalLayout_2->addLayout(horizontalLayout_13);


        verticalLayout_4->addLayout(verticalLayout_2);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        clientsBox = new QComboBox(centralwidget);
        clientsBox->setObjectName(QString::fromUtf8("clientsBox"));

        horizontalLayout_3->addWidget(clientsBox);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        commandsBox = new QComboBox(centralwidget);
        commandsBox->setObjectName(QString::fromUtf8("commandsBox"));

        horizontalLayout_4->addWidget(commandsBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        verticalLayout_3->addWidget(sendButton);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_17->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_17);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout_8->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1076, 26));
        menuNetwork = new QMenu(menubar);
        menuNetwork->setObjectName(QString::fromUtf8("menuNetwork"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuNetwork->menuAction());
        menuNetwork->addAction(actionStartServer);
        menuNetwork->addAction(actionStopServer);
        menuNetwork->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Diplom", nullptr));
        actionStartServer->setText(QApplication::translate("MainWindow", "Start server", nullptr));
        actionStopServer->setText(QApplication::translate("MainWindow", "Stop server", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionClientsList->setText(QApplication::translate("MainWindow", "Clients list", nullptr));
        frameWindow->setText(QString());
        alphaWindow->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "From", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "B", nullptr));
        blueFromValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "G", nullptr));
        greenFromValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "R", nullptr));
        redFromValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "To", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "B", nullptr));
        blueToValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "G", nullptr));
        greenToValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "R", nullptr));
        redToValLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Client", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Command", nullptr));
        sendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
        label->setText(QApplication::translate("MainWindow", "Clients connected", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        menuNetwork->setTitle(QApplication::translate("MainWindow", "Network", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
