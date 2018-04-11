/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QLabel *load;
    QLabel *logo_4;
    QPushButton *pushButton_2;
    QWidget *page;
    QPushButton *search;
    QLineEdit *lineEdit;
    QLabel *logo;
    QScrollArea *scrollArea;
    QWidget *searchscroll;
    QPushButton *topage1_1;
    QPushButton *topage2_1;
    QPushButton *topage3_1;
    QWidget *page_2;
    QPushButton *topage1_2;
    QPushButton *topage2_2;
    QPushButton *topage3_2;
    QScrollArea *scrollArea_2;
    QWidget *searchscroll_6;
    QLabel *logo_2;
    QLineEdit *lineEdit_2;
    QPushButton *search_2;
    QWidget *page_3;
    QPushButton *topage1_3;
    QPushButton *topage2_3;
    QPushButton *topage3_3;
    QScrollArea *scrollArea_3;
    QWidget *searchscroll_7;
    QLabel *logo_3;
    QLineEdit *lineEdit_3;
    QPushButton *search_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 900);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(160, 170, 191, 80));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        load = new QLabel(page_4);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(40, 50, 41, 9));
        logo_4 = new QLabel(page_4);
        logo_4->setObjectName(QStringLiteral("logo_4"));
        logo_4->setGeometry(QRect(30, 20, 41, 9));
        pushButton_2 = new QPushButton(page_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 0, 80, 15));
        stackedWidget->addWidget(page_4);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        search = new QPushButton(page);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(120, 40, 80, 15));
        search->setAutoFillBackground(false);
        search->setFlat(false);
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 241, 31));
        logo = new QLabel(page);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(50, -20, 181, 81));
        scrollArea = new QScrollArea(page);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(50, 10, 120, 80));
        scrollArea->setWidgetResizable(true);
        searchscroll = new QWidget();
        searchscroll->setObjectName(QStringLiteral("searchscroll"));
        searchscroll->setGeometry(QRect(0, 0, 118, 78));
        scrollArea->setWidget(searchscroll);
        topage1_1 = new QPushButton(page);
        topage1_1->setObjectName(QStringLiteral("topage1_1"));
        topage1_1->setGeometry(QRect(30, 30, 80, 15));
        topage2_1 = new QPushButton(page);
        topage2_1->setObjectName(QStringLiteral("topage2_1"));
        topage2_1->setGeometry(QRect(40, 50, 80, 15));
        topage3_1 = new QPushButton(page);
        topage3_1->setObjectName(QStringLiteral("topage3_1"));
        topage3_1->setGeometry(QRect(0, 0, 80, 15));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        topage1_2 = new QPushButton(page_2);
        topage1_2->setObjectName(QStringLiteral("topage1_2"));
        topage1_2->setGeometry(QRect(50, 30, 80, 15));
        topage2_2 = new QPushButton(page_2);
        topage2_2->setObjectName(QStringLiteral("topage2_2"));
        topage2_2->setGeometry(QRect(110, 20, 80, 15));
        topage3_2 = new QPushButton(page_2);
        topage3_2->setObjectName(QStringLiteral("topage3_2"));
        topage3_2->setGeometry(QRect(10, 0, 80, 15));
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(160, 40, 120, 80));
        scrollArea_2->setWidgetResizable(true);
        searchscroll_6 = new QWidget();
        searchscroll_6->setObjectName(QStringLiteral("searchscroll_6"));
        searchscroll_6->setGeometry(QRect(0, 0, 118, 78));
        scrollArea_2->setWidget(searchscroll_6);
        logo_2 = new QLabel(page_2);
        logo_2->setObjectName(QStringLiteral("logo_2"));
        logo_2->setGeometry(QRect(160, 10, 181, 81));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 70, 241, 31));
        search_2 = new QPushButton(page_2);
        search_2->setObjectName(QStringLiteral("search_2"));
        search_2->setGeometry(QRect(230, 70, 80, 15));
        search_2->setAutoFillBackground(false);
        search_2->setFlat(false);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        topage1_3 = new QPushButton(page_3);
        topage1_3->setObjectName(QStringLiteral("topage1_3"));
        topage1_3->setGeometry(QRect(40, 10, 80, 15));
        topage2_3 = new QPushButton(page_3);
        topage2_3->setObjectName(QStringLiteral("topage2_3"));
        topage2_3->setGeometry(QRect(40, 30, 80, 15));
        topage3_3 = new QPushButton(page_3);
        topage3_3->setObjectName(QStringLiteral("topage3_3"));
        topage3_3->setGeometry(QRect(40, 50, 80, 15));
        scrollArea_3 = new QScrollArea(page_3);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(170, 60, 120, 80));
        scrollArea_3->setWidgetResizable(true);
        searchscroll_7 = new QWidget();
        searchscroll_7->setObjectName(QStringLiteral("searchscroll_7"));
        searchscroll_7->setGeometry(QRect(0, 0, 118, 78));
        scrollArea_3->setWidget(searchscroll_7);
        logo_3 = new QLabel(page_3);
        logo_3->setObjectName(QStringLiteral("logo_3"));
        logo_3->setGeometry(QRect(170, 30, 181, 81));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 90, 241, 31));
        search_3 = new QPushButton(page_3);
        search_3->setObjectName(QStringLiteral("search_3"));
        search_3->setGeometry(QRect(240, 90, 80, 15));
        search_3->setAutoFillBackground(false);
        search_3->setFlat(false);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 14));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Waagle", Q_NULLPTR));
        load->setText(QString());
        logo_4->setText(QString());
        pushButton_2->setText(QString());
        search->setText(QApplication::translate("MainWindow", "search", Q_NULLPTR));
        logo->setText(QString());
        topage1_1->setText(QString());
        topage2_1->setText(QString());
        topage3_1->setText(QString());
        topage1_2->setText(QString());
        topage2_2->setText(QString());
        topage3_2->setText(QString());
        logo_2->setText(QString());
        search_2->setText(QApplication::translate("MainWindow", "search", Q_NULLPTR));
        topage1_3->setText(QString());
        topage2_3->setText(QString());
        topage3_3->setText(QString());
        logo_3->setText(QString());
        search_3->setText(QApplication::translate("MainWindow", "search", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
