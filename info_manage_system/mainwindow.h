#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_in_out_account_clicked();

    void on_account_card_borrow_clicked();

    void on_search_clicked();

    void connect_database();

private:
    void set_pushButton();
    void init();
    void restoreToolButton();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
