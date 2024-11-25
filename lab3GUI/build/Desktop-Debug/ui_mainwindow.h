/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnAddEmployee;
    QPushButton *btnDisplayEmployees;
    QPushButton *btnRemoveEmployee;
    QPushButton *btnUpdateSalary;
    QPushButton *btnSaveExit;
    QTableWidget *tableEmployees;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnAddEmployee = new QPushButton(centralwidget);
        btnAddEmployee->setObjectName(QString::fromUtf8("btnAddEmployee"));
        btnAddEmployee->setGeometry(QRect(330, 280, 151, 26));
        btnDisplayEmployees = new QPushButton(centralwidget);
        btnDisplayEmployees->setObjectName(QString::fromUtf8("btnDisplayEmployees"));
        btnDisplayEmployees->setGeometry(QRect(330, 320, 151, 26));
        btnRemoveEmployee = new QPushButton(centralwidget);
        btnRemoveEmployee->setObjectName(QString::fromUtf8("btnRemoveEmployee"));
        btnRemoveEmployee->setGeometry(QRect(330, 360, 151, 26));
        btnUpdateSalary = new QPushButton(centralwidget);
        btnUpdateSalary->setObjectName(QString::fromUtf8("btnUpdateSalary"));
        btnUpdateSalary->setGeometry(QRect(330, 400, 151, 26));
        btnSaveExit = new QPushButton(centralwidget);
        btnSaveExit->setObjectName(QString::fromUtf8("btnSaveExit"));
        btnSaveExit->setGeometry(QRect(330, 440, 151, 26));
        tableEmployees = new QTableWidget(centralwidget);
        if (tableEmployees->columnCount() < 9)
            tableEmployees->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableEmployees->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        tableEmployees->setObjectName(QString::fromUtf8("tableEmployees"));
        tableEmployees->setGeometry(QRect(60, 10, 691, 221));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnAddEmployee->setText(QCoreApplication::translate("MainWindow", "Add Employee", nullptr));
        btnDisplayEmployees->setText(QCoreApplication::translate("MainWindow", "Display Employees", nullptr));
        btnRemoveEmployee->setText(QCoreApplication::translate("MainWindow", "Remove Employee", nullptr));
        btnUpdateSalary->setText(QCoreApplication::translate("MainWindow", "Update Salary", nullptr));
        btnSaveExit->setText(QCoreApplication::translate("MainWindow", "Save & Exit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEmployees->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployees->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Full name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployees->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployees->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Sex", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployees->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployees->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Passport", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableEmployees->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Position code", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableEmployees->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Salary", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableEmployees->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
