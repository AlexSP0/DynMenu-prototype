#ifndef MENUACTIONSCONTAINER_H
#define MENUACTIONSCONTAINER_H

#include "basemenuactionscontainer.h"
#include "iactionscontainer.h"

#include <QMainWindow>

class MenuBarActionsContainer : public IActionsContainer
{
public:
    MenuBarActionsContainer(QMainWindow *window);
    ~MenuBarActionsContainer();

    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group) override;
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group) override;
    virtual Command *addSeparator(QUuid group) override;
    virtual bool deleteMenu(QUuid idu) override;
    virtual bool deleteAction(QUuid id) override;

    QMenu *getMenu() override;

    QUuid getId() override;

    QMenuBar *getMenuBar();

private slots:
    void destroyCommand(QObject *command);
    void destroyMenu(QObject *menu);

private:
    QUuid m_id;

    IBaseMenuActionsContainer *m_container;

    QMenuBar *m_menuBar;

    QWidget *m_window;
};

#endif // MENUACTIONSCONTAINER_H
