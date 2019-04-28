#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QCloseEvent>
#include <data_struct.h>
#include <QSqlError>
#include <QSqlRecord>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void searchResult(Account_info account_info);

private slots:
    void on_in_out_account_clicked();

    void on_account_card_borrow_clicked();

    void on_search_clicked();

    void connect_database(QString usr, QString passwd);

    void connect_database_();

    void addAccount(Account_info account_info);

    void searchStuInfo(Account_info account_info);

    void addOutAccountTime(Account_info account_info);

private:
    void set_pushButton();
    void init();
    void restoreToolButton();
    void closeEvent(QCloseEvent *event);
    void createDir();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery qsQuery;
};

#endif // MAINWINDOW_H
