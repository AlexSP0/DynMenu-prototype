#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <mcore/imenumanager.h>

//#include "../mcore/menuactionsmanager.h"

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
    MainWindow(IMenuManager *menuManager, QWidget *parent = nullptr);
    ~MainWindow();

    void setMenuId(QUuid id);

private slots:
    void on_pushButton_clicked();

    void onCustomContextMenuRequested(QPoint);

private:
    Ui::MainWindow *ui;

    IMenuManager *m_menuManager;
};
#endif // MAINWINDOW_H
