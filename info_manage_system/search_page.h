#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H

#include <QFrame>
#include <data_struct.h>

namespace Ui {
class SEARCH_PAGE;
}

class SEARCH_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit SEARCH_PAGE(QWidget *parent = nullptr);
    ~SEARCH_PAGE();

public slots:
    void searchResult_mult(Account_info account_info);

signals:
    void searchByMultiCodt(Account_info account_info);

private slots:
    void on_searchButton_clicked();

private:
    void set_pushuButton();

private:
    Ui::SEARCH_PAGE *ui;
};

#endif // SEARCH_PAGE_H
