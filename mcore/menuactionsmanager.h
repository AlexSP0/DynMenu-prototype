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

    /*!
     * \brief registerAction - создает, регистрирует QAction в нужном меню. Если не
     * указывать в каком, то в QMenuBar
     * \param actionName - название
     * \param menu указатель на ранее зарегистрированное меню, куда будет добавлен QAction
     * \return nullptr в случае ошибки или указатель на объект типа Command c созданным объектом QAction
     */
    Command *registerAction(QString actionName, Command *menu = nullptr);
    /*!
     * \brief registerMenu registerAction - создает, регистрирует QMenu в нужном меню. Если не
     * указывать в каком, то в QMenuBar
     * \param menuName - название меню
     * \param menu - указатель на ранее зарегистрированное меню, куда будет добавлен QAction
     * \return nullptr в случае ошибки или указатель на объект типа Command c созданным объектом QAction
     */
    Command *registerMenu(QString menuName, Command *menu = nullptr);

    /*!
     * \brief unregisterAction - удаляет ранее зарегистрированный QAction
     * \param command - указатель на объект Command, возвращенный при регистрации
     * \return false в случае ошибки, true - в случае удачного удаления
     */
    bool unregisterAction(Command *command);
    /*!
     * \brief unregisterMenu - удаляет ранее зарегистрированный QMenu
     * \param command - указатель на объект Command, возвращенный при регистрации
     * \return false в случае ошибки, true - в случае удачного удаления
     */
    bool unregisterMenu(Command *command);

private:
    QMainWindow *m_mainWindow;

    QMenuBar *m_menuBar;

    QMap<QUuid, std::shared_ptr<Command>> m_actions;

private:
    bool insertAction(Command *action, Command *destination);
    bool insertActionInMenu(Command *action, QMenu *destination, QMenu *currentSearchMenu);

    bool removeAction(Command *action);
    bool removeActionInMenu(Command *action, QMenu *currentSearchMenu);
};

#endif // MENUACTIONSMANAGER_H
