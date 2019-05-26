#ifndef IN_OUT_ACCOUNT_PAGE_H
#define IN_OUT_ACCOUNT_PAGE_H

#include <QFrame>
#include <QMessageBox>
#include <QFileDialog>
#include <data_struct.h>
#include <QDebug>
#include <QImage>
#include <QDateTime>
#include <QTime>
//#include <readcard.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QThread>

namespace Ui {
class IN_OUT_ACCOUNT_PAGE;
}

class IN_OUT_ACCOUNT_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit IN_OUT_ACCOUNT_PAGE(QWidget *parent = nullptr);
    ~IN_OUT_ACCOUNT_PAGE();

signals:
    void addAccount(Account_info account_info);
    void inputNameAndStuId(Account_info account_info);
    void addOutAccountTime(Account_info account_info);
    void getCard_ID(Card_info card);
    void import_account_info(QString);


public slots:
    void empty_lineEdit();
    void searchResult(Account_info account_info);


private slots:
    void on_searchButton_clicked();

    void on_uploadPhoto_clicked();

    void on_readCardButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_readCardButton_2_clicked();

    void on_concelButton_clicked();

    void on_concelButton_2_clicked();

    void on_okButton_clicked();

    void on_okButton_2_clicked();

    void on_importButton_clicked();

    void on_importButton_2_clicked();

private:
    void set_pushButton();
    void empty_lineEdit_2();

private:
    Ui::IN_OUT_ACCOUNT_PAGE *ui;
    QString photoPath_;
    int index_;
    bool isDate(QString);
};

#endif // IN_OUT_ACCOUNT_PAGE_H
