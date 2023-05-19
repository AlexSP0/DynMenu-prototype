#ifndef IMENUMANAGEABLEWINDOW_H
#define IMENUMANAGEABLEWINDOW_H

#include <QMenuBar>

class IMenuManageableWindow
{
public:
    virtual QMenuBar *getMenuBar() = 0;
};

#endif // IMENUMANAGEABLEWINDOW_H
