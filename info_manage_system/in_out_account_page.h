#ifndef IN_OUT_ACCOUNT_PAGE_H
#define IN_OUT_ACCOUNT_PAGE_H

#include <QFrame>
#include <QtSql>

namespace Ui {
class IN_OUT_ACCOUNT_PAGE;
}

class IN_OUT_ACCOUNT_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit IN_OUT_ACCOUNT_PAGE(QWidget *parent = nullptr);
    ~IN_OUT_ACCOUNT_PAGE();

private slots:
    void on_in_accountButton_clicked();

    void on_out_accountButton_clicked();

    void on_write_concelButton_clicked();

    void init_in_out_account_page();

    void restore_lineEdit_and_PushBuuton();

    void empty_lineEdit();

    void on_searchButton_clicked();

private:
    void set_pushButton();

private:
    Ui::IN_OUT_ACCOUNT_PAGE *ui;
};

#endif // IN_OUT_ACCOUNT_PAGE_H
