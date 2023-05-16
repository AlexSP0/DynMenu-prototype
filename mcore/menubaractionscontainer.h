#ifndef MENUACTIONSCONTAINER_H
#define MENUACTIONSCONTAINER_H

#include "iactionscontainer.h"

class MenuBarActionsContainer : public IActionsContainer
{
public:
    MenuBarActionsContainer(QString title);

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid idu) override;
    virtual bool deleteAction(QUuid id) override;

    void setDefaultBehavior();
    QMenu *getMenu();
    QUuid getId();

    QMenuBar *getMenuBar();

protected:
    bool appendAction(std::shared_ptr<Command> command, QUuid group);
    bool removeAction(QUuid id);

    bool appendMenu(std::shared_ptr<IActionsContainer> menu, QUuid group);
    bool removeMenu(QUuid id);

private slots:
    void destroyCommand(QObject *command);
    void destroyMenu(QObject *menu);

private:
    QUuid m_id;

    std::unique_ptr<QMenuBar> m_menuBar;

    std::map<QUuid, std::shared_ptr<Command>> m_actions;

    std::map<QUuid, std::shared_ptr<IActionsContainer>> m_menus;

    OnAllDisabledBehavior m_disableBehavior;

    // IActionsContainer interface
public:
};

#endif // MENUACTIONSCONTAINER_H
