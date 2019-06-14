#ifndef SEARCHPAGE_H
#define SEARCHPAGE_H

#include <QWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include "data_struct.h"

namespace Ui {
class SearchPage;
}

class SearchPage : public QWidget
{
    Q_OBJECT

public:
    explicit SearchPage(QWidget *parent = nullptr);
    ~SearchPage();

public slots:
    void searchResult_m(Account_info, BorrowCard);

signals:
    void searchByMultiCodt(Account_info, BorrowCard);

private slots:
    void on_searchButton_clicked();

    void on_exportButton_clicked();

private:
    Ui::SearchPage *ui;
    int rowCur = 0;
    bool isDate(QString);
    QString dealDate(QString);
};

#endif // SEARCHPAGE_H
