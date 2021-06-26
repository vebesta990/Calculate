#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(n1);                                   // Задать строку в матрице A
    ui->tableWidget->setColumnCount(m1);                                // Задать столбец в матрице A
    ui->tableWidget_2->setRowCount(m1);                                 // Задать строку в матрице A (транспонированная)
    ui->tableWidget_2->setColumnCount(n1);                              // Задать столбец в матрице A (транспонированная)
    this->item = 0;
    for(int i = 0; i < this->n1; i++) {
        for (int j = 0; j < this->m1; j++) {
            QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(item));
            ui->tableWidget->setItem(i, j, tbl);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()                              // Добавить 1 строку к матрице A
{
    ui->tableWidget->setRowCount(this->n1+1);
    ui->tableWidget_2->setColumnCount(this->n1+1);
    this->n1 = this->n1+1;
    for(int i = 0; i < this->n1; i++) {
        for (int j = 0; j < this->m1; j++) {
            QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(this->item));
            ui->tableWidget->setItem(i, j, tbl);
        }
    }
}

void MainWindow::on_pushButton_3_clicked()                              // Убрать 1 строку у матрицы A
{
    if (this->n1!=1){
        ui->tableWidget->setRowCount(this->n1-1);
        ui->tableWidget_2->setColumnCount(this->n1-1);
        this->n1 = this->n1-1;
    }
}

void MainWindow::on_pushButton_4_clicked()                              // Добаить 1 столбец к матрице A
{
    ui->tableWidget->setColumnCount(this->m1+1);
    ui->tableWidget_2->setRowCount(this->m1+1);
    this->m1 = this->m1+1;
    for(int i = 0; i < this->n1; i++) {
        for (int j = 0; j < this->m1; j++) {
            QTableWidgetItem *tbl = new QTableWidgetItem(QString::number(this->item));
            ui->tableWidget->setItem(i, j, tbl);
        }
    }
}

void MainWindow::on_pushButton_5_clicked()                              // Убрать 1 столбец у матрицы A
{
    if (this->m1!=1){
        ui->tableWidget->setColumnCount(this->m1-1);
        ui->tableWidget_2->setRowCount(this->m1-1);
        this->m1 = this->m1-1;
    }
}

void MainWindow::on_pushButton_clicked()                                // Выполнить транспонирование
{
    double str;
    for(int i = 0; i < this->m1; i++) {
        for (int j = 0; j < this->n1; j++) {
            str = ui->tableWidget->item(j,i)->text().toDouble();
            ui->tableWidget_2->setItem(i, j,new QTableWidgetItem(QString::number(str*1)));
        }
    }
}
