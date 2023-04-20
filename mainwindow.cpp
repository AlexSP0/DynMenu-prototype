#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_menuManager(new MenuActionsManager(this))
{
    ui->setupUi(this);

    connect(m_menuManager.get(), &MenuActionsManager::addAction, this, &MainWindow::addAction);
    connect(m_menuManager.get(), &MenuActionsManager::addMenu, this, &MainWindow::addMenu);
    connect(m_menuManager.get(), &MenuActionsManager::removeAction, this, &MainWindow::removeAction);
    connect(m_menuManager.get(), &MenuActionsManager::removeMenu, this, &MainWindow::removeMenu);
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

void MainWindow::addMenu(QAction *subMenu, Command *menu)
{
    if (!menu)
    {
        ui->menubar->addMenu(subMenu->menu());
    }
    else
    {
        for (QAction *currentAction : ui->menubar->actions())
        {
            QMenu *currentMenu = currentAction->menu();
            if (currentMenu)
            {
                if (currentAction == menu->m_menu->menuAction())
                {
                    currentMenu->addAction(subMenu);
                }
                else
                {
                    addActionInMenu(subMenu, menu->m_menu.get(), currentMenu);
                }
            }
        }
    }
}

void MainWindow::removeMenu(QAction *menu)
{
    ui->menubar->removeAction(menu);
}

void MainWindow::addAction(QAction *action, Command *menu)
{
    if (!menu)
    {
        ui->menubar->addAction(action);
    }
    else
    {
        for (QAction *currentAction : ui->menubar->actions())
        {
            QMenu *currentMenu = currentAction->menu();
            if (currentMenu)
            {
                if (currentAction == menu->m_menu->menuAction())
                {
                    currentMenu->addAction(action);
                }
                else
                {
                    addActionInMenu(action, menu->m_menu.get(), currentMenu);
                }
            }
        }
    }
}

void MainWindow::removeAction(QAction *action)
{
    for (auto currentAction : ui->menubar->actions())
    {
        if (action == currentAction)
        {
            ui->menubar->removeAction(action);
        }

        if (currentAction->menu())
        {
            deleteActionFromMenu(action, currentAction->menu());
        }
    }
}

void MainWindow::deleteActionFromMenu(QAction *action, QMenu *menu)
{
    for (auto currentAction : menu->actions())
    {
        if (action == currentAction)
        {
            menu->removeAction(currentAction);
        }
        if (currentAction->menu())
        {
            deleteActionFromMenu(action, currentAction->menu());
        }
    }
}

void MainWindow::addActionInMenu(QAction *action, QMenu *menu, QMenu *currentSearchMenu)
{
    for (QAction *currentAction : currentSearchMenu->actions())
    {
        QMenu *currentMenu = currentAction->menu();

        if (currentMenu)
        {
            if (menu->menuAction() == currentMenu->menuAction())
            {
                currentMenu->addAction(action);
            }
            else
            {
                addActionInMenu(action, menu, currentMenu);
            }
        }
    }
}
