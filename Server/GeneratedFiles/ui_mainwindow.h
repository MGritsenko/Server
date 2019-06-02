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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *actionOpenFile;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *frameWindow;
    QGridLayout *gridLayout;
    QLabel *alphaWindow;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *clientsListLayout;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QComboBox *clientsBox;
    QComboBox *commandsBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *doneSetup;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *sendColorButton;
    QPushButton *getPhoneAreasButton;
    QPushButton *sendVideoButton;
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
        MainWindow->resize(1306, 773);
        actionStartServer = new QAction(MainWindow);
        actionStartServer->setObjectName(QString::fromUtf8("actionStartServer"));
        actionStopServer = new QAction(MainWindow);
        actionStopServer->setObjectName(QString::fromUtf8("actionStopServer"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionClientsList = new QAction(MainWindow);
        actionClientsList->setObjectName(QString::fromUtf8("actionClientsList"));
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frameWindow = new QLabel(centralwidget);
        frameWindow->setObjectName(QString::fromUtf8("frameWindow"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frameWindow->sizePolicy().hasHeightForWidth());
        frameWindow->setSizePolicy(sizePolicy);
        frameWindow->setMinimumSize(QSize(640, 360));
        frameWindow->setMaximumSize(QSize(640, 360));
        frameWindow->setFrameShape(QFrame::Box);
        frameWindow->setFrameShadow(QFrame::Plain);
        frameWindow->setWordWrap(true);

        horizontalLayout_2->addWidget(frameWindow);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        alphaWindow = new QLabel(centralwidget);
        alphaWindow->setObjectName(QString::fromUtf8("alphaWindow"));
        alphaWindow->setMinimumSize(QSize(640, 360));
        alphaWindow->setMaximumSize(QSize(640, 360));
        alphaWindow->setFrameShape(QFrame::Box);
        alphaWindow->setWordWrap(true);

        gridLayout->addWidget(alphaWindow, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout_4->addLayout(horizontalLayout_2);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        clientsListLayout = new QHBoxLayout();
        clientsListLayout->setObjectName(QString::fromUtf8("clientsListLayout"));

        verticalLayout_5->addLayout(clientsListLayout);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        clientsBox = new QComboBox(centralwidget);
        clientsBox->setObjectName(QString::fromUtf8("clientsBox"));

        verticalLayout_2->addWidget(clientsBox);

        commandsBox = new QComboBox(centralwidget);
        commandsBox->setObjectName(QString::fromUtf8("commandsBox"));

        verticalLayout_2->addWidget(commandsBox);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        doneSetup = new QCheckBox(centralwidget);
        doneSetup->setObjectName(QString::fromUtf8("doneSetup"));

        verticalLayout_3->addWidget(doneSetup);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sendColorButton = new QPushButton(centralwidget);
        sendColorButton->setObjectName(QString::fromUtf8("sendColorButton"));

        horizontalLayout_4->addWidget(sendColorButton);

        getPhoneAreasButton = new QPushButton(centralwidget);
        getPhoneAreasButton->setObjectName(QString::fromUtf8("getPhoneAreasButton"));

        horizontalLayout_4->addWidget(getPhoneAreasButton);

        sendVideoButton = new QPushButton(centralwidget);
        sendVideoButton->setObjectName(QString::fromUtf8("sendVideoButton"));

        horizontalLayout_4->addWidget(sendVideoButton);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

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


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1306, 26));
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
        menuFile->addAction(actionOpenFile);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Diplom", nullptr));
        actionStartServer->setText(QApplication::translate("MainWindow", "Start server", nullptr));
        actionStopServer->setText(QApplication::translate("MainWindow", "Stop server", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionClientsList->setText(QApplication::translate("MainWindow", "Clients list", nullptr));
        actionOpenFile->setText(QApplication::translate("MainWindow", "Open File", nullptr));
        frameWindow->setText(QString());
        alphaWindow->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Client", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Command", nullptr));
        doneSetup->setText(QApplication::translate("MainWindow", "Done setup", nullptr));
        sendColorButton->setText(QApplication::translate("MainWindow", "SEND COLOR", nullptr));
        getPhoneAreasButton->setText(QApplication::translate("MainWindow", "GET PHONE AREAS", nullptr));
        sendVideoButton->setText(QApplication::translate("MainWindow", "SEND VIDEO", nullptr));
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
