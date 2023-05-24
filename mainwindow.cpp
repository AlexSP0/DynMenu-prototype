#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(IMenuManager *menuManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_menuManager(menuManager)
{
    ui->setupUi(this);

    ui->toolBar->addAction(QIcon::fromTheme("document-open"), "New File");
    ui->toolBar->addAction(QIcon::fromTheme("document-save"), "Open File");
    ui->toolBar->addSeparator();

    ui->centralwidget->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->centralwidget, &QWidget::customContextMenuRequested, this, &MainWindow::onCustomContextMenuRequested);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {}

void MainWindow::onCustomContextMenuRequested(QPoint pos) {}
