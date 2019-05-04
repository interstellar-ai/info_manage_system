#ifndef ACCOUNT_CARD_BORROW_PAGE_H
#define ACCOUNT_CARD_BORROW_PAGE_H

#include <QFrame>
#include <QMessageBox>
#include <data_struct.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QTime>
//#include <readcard.h>

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
    void addTime(Account_info account_info);
    void readStu_ID_info(Account_info account_info);

public slots:
    void searchResult(Account_info account_info);

    void empty_lineEdit();

private slots:
    void on_borrowButton_clicked();

    void on_returnButton_clicked();

    void on_searchButton_clicked();

    void on_write_concelButton_clicked();

    void on_write_OKButton_clicked();

    void on_readCardButton_clicked();

    void on_updateData_clicked();



private:
    Ui::ACCOUNT_CARD_BORROW_PAGE *ui;
    void init_in_out_account_page();

    void restore_lineEdit_and_PushBuuton();
    void set_pushButton();
    int index;
};

#endif // ACCOUNT_CARD_BORROW_PAGE_H
