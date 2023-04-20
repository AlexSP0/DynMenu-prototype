#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../mcore/menuactionsmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    MenuActionsManager *getMenuManager();

private slots:
    void on_pushButton_clicked();

private slots:
    void addMenu(QAction *subMenu, Command *menu);
    void removeMenu(QAction *menu);
    void addAction(QAction *action, Command *menu);
    void removeAction(QAction *action);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<MenuActionsManager> m_menuManager;

private:
    void deleteActionFromMenu(QAction *action, QMenu *menu);

    void addActionInMenu(QAction *action, QMenu *menu, QMenu *currentSearchMenu);
};
#endif // MAINWINDOW_H
