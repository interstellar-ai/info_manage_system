#ifndef GETCARDUID_H
#define GETCARDUID_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include "data_struct.h"


namespace Ui {
class GetCardUID;
}

class GetCardUID : public QWidget
{
    Q_OBJECT

public:
    explicit GetCardUID(QWidget *parent = nullptr);
    ~GetCardUID();

signals:
    void save_UID_StuID(Card_info);
    void unitedCard(Card_info);
    void searchCardUID(Card_info);

public slots:
    void searchCardUIDRes(Card_info);

private slots:

    void on_readButton_clicked();

    void on_entryButton_clicked();

    void on_clearButton_clicked();

    void on_untiedBut_clicked();

    void on_searchBut_clicked();

private:
    Ui::GetCardUID *ui;
};

#endif // GETCARDUID_H
