#ifndef ACCOUNT_CARD_BORROW_PAGE_H
#define ACCOUNT_CARD_BORROW_PAGE_H

#include <QFrame>
#include <QMessageBox>
#include <data_struct.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QFileDialog>
#include <QTime>

namespace Ui {
class ACCOUNT_CARD_BORROW_PAGE;
}

class ACCOUNT_CARD_BORROW_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit ACCOUNT_CARD_BORROW_PAGE(QWidget *parent = nullptr);
    ~ACCOUNT_CARD_BORROW_PAGE();

signals:
    void inputNameAndStuId(Account_info account_info);
    void getCard_ID_1(Card_info);
    void getCard_ID_2(Card_info);
    void addBorrowDate(BorrowCard);
    void addBackDate(BorrowCard);
    void searchBorrowTime(BorrowCard);
    void borrow_record_import(QString);

public slots:
    void searchResult(Account_info account_info);
    void searchResult_2(BorrowCard);
    void searchResult_4(Account_info account_info);

private slots:

    void on_searchButton_clicked();

    void on_readCardButton_clicked();

    void on_updateData_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_okButton_clicked();

    void on_okButton_2_clicked();

    void on_readCardButton_2_clicked();

    void on_concelButton_clicked();

    void on_concelButton_2_clicked();

    void on_searchButton_2_clicked();

    void on_importButton_2_clicked();

    void on_importButton_clicked();

private:
    Ui::ACCOUNT_CARD_BORROW_PAGE *ui;
    void empty_lineEdit();
    void empty_lineEdit_2();
    void set_pushButton();
    bool isDate(QString);
    int index_;
    QString photoPath_;
    const QString format = "yyyy-MM-dd";
};

#endif // ACCOUNT_CARD_BORROW_PAGE_H
