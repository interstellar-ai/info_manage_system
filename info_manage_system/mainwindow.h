#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QCloseEvent>

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

    void connect_database(QString usr, QString passwd);

private:
    void set_pushButton();
    void init();
    void restoreToolButton();
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery qsQuery;
};

#endif // MAINWINDOW_H
