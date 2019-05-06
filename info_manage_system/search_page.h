#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H

#include <QFrame>
#include <QDebug>
#include <data_struct.h>
#include <QByteArray>

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
    void searchResult_s(Account_info account_info);

signals:
    void searchedText(QString text);
    void searchByMultiCodt(Account_info account_info);

private slots:
    void on_searchButton_clicked();
    void showText(QString text);

private:
    void set_pushuButton();

//    void showText(QByteArray);

private:
    Ui::SEARCH_PAGE *ui;
};

#endif // SEARCH_PAGE_H
