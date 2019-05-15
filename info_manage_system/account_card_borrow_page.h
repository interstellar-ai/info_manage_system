#ifndef ACCOUNT_CARD_BORROW_PAGE_H
#define ACCOUNT_CARD_BORROW_PAGE_H

#include <QFrame>
#include <QMessageBox>
#include <data_struct.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
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
    void getCard_ID(Card_info card);
    void addBorrowDate(BorrowCard);
    void addBackDate(BorrowCard);
    void searchBorrowTime(BorrowCard);

public slots:
    void searchResult(Account_info account_info);
    void searchResult_2(BorrowCard);

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

private:
    Ui::ACCOUNT_CARD_BORROW_PAGE *ui;
    void empty_lineEdit();
    void empty_lineEdit_2();
    void set_pushButton();
    int index_;
    QString photoPath_;
    const QString format = "yyyy-MM-dd";
};

#endif // ACCOUNT_CARD_BORROW_PAGE_H
