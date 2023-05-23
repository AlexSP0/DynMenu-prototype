#ifndef UICONTAINER_H
#define UICONTAINER_H

#include "iactionscontainer.h"
#include "ibasemenuactionscontainer.h"

#include "iuielement.h"

#include <QMenuBar>

class UiContainer : public IActionsContainer
{
    UiContainer();

public:
    UiContainer(QMenu *menu);
    UiContainer(QMenuBar *menuBar);

    virtual ~UiContainer();

    virtual std::weak_ptr<Command> addAction(QAction *action, QUuid group);
    virtual std::weak_ptr<IActionsContainer> addMenu(QMenu *menu, QUuid group);
    virtual Command *addSeparator(QUuid group);

    virtual QMenu *getMenu() override;
    virtual QMenuBar *getMenuBar() override;
    virtual std::weak_ptr<Command> getActionById(QUuid id) override;
    std::weak_ptr<IActionsContainer> getMenuById(QUuid id) override;

    virtual QUuid getId();
    void setId(QUuid id);

    virtual bool deleteMenu(QUuid id);
    virtual bool deleteAction(QUuid id);

private slots:
    virtual void destroyCommand(QObject *command);
    virtual void destroyMenu(QObject *menu);

private:
    QUuid m_id;

    IBaseMenuActionsContainer *m_container;

    IUiElement *m_element;
};

#endif
