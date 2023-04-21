#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_menuManager(nullptr)
{
    ui->setupUi(this);

    m_menuManager = std::make_unique<MenuActionsManager>(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MenuActionsManager *MainWindow::getMenuManager()
{
    return m_menuManager.get();
}

void MainWindow::on_pushButton_clicked() {}
