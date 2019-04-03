#ifndef ACCOUNT_CARD_BORROW_PAGE_H
#define ACCOUNT_CARD_BORROW_PAGE_H

#include <QFrame>

namespace Ui {
class ACCOUNT_CARD_BORROW_PAGE;
}

class ACCOUNT_CARD_BORROW_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit ACCOUNT_CARD_BORROW_PAGE(QWidget *parent = nullptr);
    ~ACCOUNT_CARD_BORROW_PAGE();

private slots:
    void on_borrowButton_clicked();

    void on_returnButton_clicked();

    void on_write_concel_Button_clicked();

    void on_searchButton_clicked();

private:
    Ui::ACCOUNT_CARD_BORROW_PAGE *ui;
    void init_in_out_account_page();
    void empty_lineEdit();
    void restore_lineEdit_and_PushBuuton();
};

#endif // ACCOUNT_CARD_BORROW_PAGE_H
