/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *ros_ip_label;
    QLabel *topics_label;
    QLabel *nodes_label;
    QTextEdit *topics_textEdit;
    QTextEdit *nodes_textEdit;
    QTextEdit *ros_ip_textEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 367);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ros_ip_label = new QLabel(centralWidget);
        ros_ip_label->setObjectName(QStringLiteral("ros_ip_label"));
        ros_ip_label->setGeometry(QRect(20, 30, 81, 21));
        QFont font;
        font.setPointSize(14);
        ros_ip_label->setFont(font);
        topics_label = new QLabel(centralWidget);
        topics_label->setObjectName(QStringLiteral("topics_label"));
        topics_label->setGeometry(QRect(30, 80, 59, 14));
        nodes_label = new QLabel(centralWidget);
        nodes_label->setObjectName(QStringLiteral("nodes_label"));
        nodes_label->setGeometry(QRect(300, 80, 59, 14));
        topics_textEdit = new QTextEdit(centralWidget);
        topics_textEdit->setObjectName(QStringLiteral("topics_textEdit"));
        topics_textEdit->setGeometry(QRect(10, 110, 231, 191));
        topics_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        topics_textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        nodes_textEdit = new QTextEdit(centralWidget);
        nodes_textEdit->setObjectName(QStringLiteral("nodes_textEdit"));
        nodes_textEdit->setGeometry(QRect(290, 110, 161, 191));
        ros_ip_textEdit = new QTextEdit(centralWidget);
        ros_ip_textEdit->setObjectName(QStringLiteral("ros_ip_textEdit"));
        ros_ip_textEdit->setGeometry(QRect(100, 30, 251, 21));
        ros_ip_textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 30, 80, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ros_ip_label->setText(QApplication::translate("MainWindow", "ROS_IP", Q_NULLPTR));
        topics_label->setText(QApplication::translate("MainWindow", "topics", Q_NULLPTR));
        nodes_label->setText(QApplication::translate("MainWindow", "nodes", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "check", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
