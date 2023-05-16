#ifndef MENUACTIONSCONTAINER_H
#define MENUACTIONSCONTAINER_H

#include "basemenuactionscontainer.h"
#include "iactionscontainer.h"

class MenuBarActionsContainer : public IActionsContainer
{
public:
    MenuBarActionsContainer(QString title);
    ~MenuBarActionsContainer();

    virtual Command *addAction(QAction *action, QUuid group) override;
    virtual IActionsContainer *addMenu(QString title, QUuid group) override;
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
};

#endif // MENUACTIONSCONTAINER_H
