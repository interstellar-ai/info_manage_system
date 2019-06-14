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
#include <QAxBase>
#include <QAxObject>
//#include <readcard.h>
#include <QThread>
#include "excelengine.h"

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
    void searchResult_3(BorrowCard);
    void searchResult_4(Account_info account_info);
    void searchResult_2(Account_info account_info);

    void searchResult_m(Account_info, BorrowCard);
    void searchCardUIDRes(Card_info);
    void empty_lineEdit();

private slots:
    void on_in_out_account_clicked();

    void on_account_card_borrow_clicked();

    void on_search_clicked();

    void connect_database(QString usr, QString passwd);

    void connect_database_();

    void addAccount(Account_info account_info);

    void searchStuInfo(Account_info account_info);

    void searchStuInfo_2(Account_info account_info);

    void addOutAccountTime(Account_info account_info);

    void getCard_ID(Card_info card);

    void getCard_ID_1(Card_info card);

    void getCard_ID_2(Card_info card);

    void searchByMultiCodt(Account_info, BorrowCard);

    void on_readCardButton_clicked();

    void save_UID_StuID(Card_info);

    void addBorrowDate(BorrowCard);

    void addBackDate(BorrowCard);

    void searchBorrowTime(BorrowCard);

    void borrow_record_import(QString);

    void import_account_info(QString);

    void unitedCard(Card_info);

    void searchCardUID(Card_info);

private:
    void set_pushButton();
    void init();
    void restoreToolButton();
    void closeEvent(QCloseEvent *event);
    void createDir();
    void createMySQL_Table();
    void getSearchResult(QString stm, Account_info, BorrowCard);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery qsQuery;
//    ReadCard readCard;
//    QThread readCardThread;
};

#endif // MAINWINDOW_H
