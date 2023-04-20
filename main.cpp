#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto m       = w.getMenuManager();
    auto menuPtr = m->registerMenu("SubMenu");

    auto action0Ptr = m->registerAction("Action0");

    auto actionPtr = m->registerAction("Action", menuPtr);

    auto actionPtr2 = m->registerAction("Action2", menuPtr);

    auto actionPtr3 = m->registerAction("Action3", menuPtr);

    auto subSubMenu0Ptr = m->registerMenu("SubSubMenu0", menuPtr);

    auto subSubMenu1Ptr = m->registerMenu("SubSubMenu1", menuPtr);

    auto subSubSubMenu0Ptr = m->registerMenu("SubSubSubMenu0", subSubMenu0Ptr);

    auto subSubSubSubMenu0Ptr = m->registerMenu("SubSubSubSubMenu0", subSubSubMenu0Ptr);

    auto subSubSubSubMenu1Ptr = m->registerMenu("SubSubSubSubMenu1", subSubSubMenu0Ptr);

    auto subsubsubAction0 = m->registerAction("subsubsubAction0", subSubSubMenu0Ptr);

    auto subsubsubsubAction0 = m->registerAction("subsubsubsubAction0", subSubSubSubMenu0Ptr);

    auto subsubsubsubAction1 = m->registerAction("subsubsubsubAction1", subSubSubSubMenu0Ptr);

    //bool action3Result = m->unregisterAction(actionPtr3);

    bool menuResult = m->unregisterMenu(subSubSubSubMenu1Ptr);

    bool actionResult = m->unregisterAction(subsubsubsubAction1);

    w.show();

    return a.exec();
}
