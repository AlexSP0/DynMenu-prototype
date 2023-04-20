#ifndef MENUACTIONSMANAGER_H
#define MENUACTIONSMANAGER_H

#include "command.h"

#include <memory>
#include <QMainWindow>
#include <QMenuBar>
#include <QUuid>

class MenuActionsManager : public QObject
{
public:
    Q_OBJECT
public:
    MenuActionsManager(QMainWindow *mainMenu);

    Command *registerAction(QString actionName, Command *menu = nullptr);
    Command *registerMenu(QString menuName, Command *menu = nullptr);

    bool unregisterMenu(Command *command);
    bool unregisterAction(Command *command);

signals:
    void addMenu(QAction *subMenu, Command *menu);
    void removeMenu(QAction *menu);
    void addAction(QAction *action, Command *menu);
    void removeAction(QAction *action);

private:
    QMainWindow *m_mainWindow;
    std::vector<std::unique_ptr<Command>> m_actions;
    std::vector<std::unique_ptr<Command>> m_menus;
};

#endif // MENUACTIONSMANAGER_H
