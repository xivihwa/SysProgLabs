#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), db() {
    ui->setupUi(this);

    // Подключение кнопок к соответствующим слотам
    connect(ui->btnAddEmployee, &QPushButton::clicked, this, &MainWindow::onAddEmployeeClicked);
    connect(ui->btnDisplayEmployees, &QPushButton::clicked, this, &MainWindow::onDisplayEmployeesClicked);
    connect(ui->btnRemoveEmployee, &QPushButton::clicked, this, &MainWindow::onRemoveEmployeeClicked);
    connect(ui->btnUpdateSalary, &QPushButton::clicked, this, &MainWindow::onUpdateSalaryClicked);
    connect(ui->btnSaveExit, &QPushButton::clicked, this, &MainWindow::onSaveExitClicked);

    // Загрузка данных сотрудников из файла при запуске
    db.loadFromFile("employees.txt");
}

MainWindow::~MainWindow() {
    // Сохранение данных перед выходом
    db.saveToFile("employees.txt");
    delete ui;
}

void MainWindow::onAddEmployeeClicked() {
    bool ok;

    // Запрос ID сотрудника
    int id = QInputDialog::getInt(this, "Add Employee", "Enter ID:", 0, 0, 100000, 1, &ok);
    if (!ok) return;

    // Запрос полного имени
    QString fullName = QInputDialog::getText(this, "Add Employee", "Enter Full Name:", QLineEdit::Normal, "", &ok);
    if (!ok || fullName.isEmpty()) return;

    // Запрос возраста
    int age = QInputDialog::getInt(this, "Add Employee", "Enter Age:", 18, 18, 100, 1, &ok);
    if (!ok) return;

    // Запрос пола
    QString gender = QInputDialog::getText(this, "Add Employee", "Enter Gender:", QLineEdit::Normal, "Male", &ok);
    if (!ok || gender.isEmpty()) return;

    // Запрос адреса
    QString address = QInputDialog::getText(this, "Add Employee", "Enter Address:", QLineEdit::Normal, "", &ok);
    if (!ok || address.isEmpty()) return;

    // Запрос паспорта
    QString passport = QInputDialog::getText(this, "Add Employee", "Enter Passport Info:", QLineEdit::Normal, "", &ok);
    if (!ok || passport.isEmpty()) return;

    // Запрос кода позиции
    int positionCode = QInputDialog::getInt(this, "Add Employee", "Enter Position Code:", 0, 0, 1000, 1, &ok);
    if (!ok) return;

    // Запрос зарплаты
    double salary = QInputDialog::getDouble(this, "Add Employee", "Enter Salary:", 0, 0, 1000000, 2, &ok);
    if (!ok) return;

    // Создание объекта Employee и добавление в базу данных
    Employee employee(id, fullName.toStdString(), age, gender.toStdString(), address.toStdString(), passport.toStdString(), positionCode, salary);
    db.addEmployee(employee);

    db.saveToFile("employees.txt");
    QMessageBox::information(this, "Success", "Employee added successfully.");
}

void MainWindow::onDisplayEmployeesClicked() {
    // Очистка таблицы
    ui->tableEmployees->setRowCount(0);

    // Получение списка сотрудников из базы данных
    const auto& employees = db.getEmployees();

    // Заполнение таблицы
    for (const auto& emp : employees) {
        int row = ui->tableEmployees->rowCount();
        ui->tableEmployees->insertRow(row);

        ui->tableEmployees->setItem(row, 0, new QTableWidgetItem(QString::number(emp.getId())));
        ui->tableEmployees->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(emp.getFullName())));
        ui->tableEmployees->setItem(row, 2, new QTableWidgetItem(QString::number(emp.getAge())));
        ui->tableEmployees->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(emp.getGender())));
        ui->tableEmployees->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(emp.getAddress())));
        ui->tableEmployees->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(emp.getPassport())));
        ui->tableEmployees->setItem(row, 6, new QTableWidgetItem(QString::number(emp.getPositionCode())));
        ui->tableEmployees->setItem(row, 7, new QTableWidgetItem(QString::number(emp.getSalary(), 'f', 2)));
        ui->tableEmployees->setItem(row, 8, new QTableWidgetItem(emp.getIsActive() ? "Active" : "Inactive"));
    }
}

void MainWindow::onRemoveEmployeeClicked() {
    bool ok;

    // Запрос ID сотрудника для удаления
    int id = QInputDialog::getInt(this, "Remove Employee", "Enter ID:", 0, 0, 100000, 1, &ok);
    if (!ok) return;

    // Удаление сотрудника
    db.removeEmployee(id);

    QMessageBox::information(this, "Success", "Employee removed successfully.");
}

void MainWindow::onUpdateSalaryClicked() {
    bool ok;

    // Запрос ID сотрудника
    int id = QInputDialog::getInt(this, "Update Salary", "Enter ID:", 0, 0, 100000, 1, &ok);
    if (!ok) return;

    // Запрос процента изменения зарплаты
    double percent = QInputDialog::getDouble(this, "Update Salary", "Enter Percentage:", 0, -100, 100, 2, &ok);
    if (!ok) return;

    // Обновление зарплаты
    db.updateSalary(id, percent);

    QMessageBox::information(this, "Success", "Salary updated successfully.");
}

void MainWindow::onSaveExitClicked() {
    // Сохранение данных в файл и выход из приложения
    db.saveToFile("employees.txt");
    QMessageBox::information(this, "Saved", "Employee data saved successfully.");
    QApplication::quit();
}
