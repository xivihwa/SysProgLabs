#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Database.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddEmployeeClicked();
    void onDisplayEmployeesClicked();
    void onRemoveEmployeeClicked();
    void onUpdateSalaryClicked();
    void onSaveExitClicked();

private:
    Ui::MainWindow *ui;
    Database db;
};

#endif // MAINWINDOW_H

