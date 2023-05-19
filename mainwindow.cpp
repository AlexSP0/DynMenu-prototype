#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar->addAction(QIcon::fromTheme("document-open"), "New File");
    ui->toolBar->addAction(QIcon::fromTheme("document-save"), "Open File");
    ui->toolBar->addSeparator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMenuBar *MainWindow::getMenuBar()
{
    return menuBar();
}

void MainWindow::on_pushButton_clicked() {}
