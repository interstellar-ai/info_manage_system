#ifndef RECORDCARDNUMBER_H
#define RECORDCARDNUMBER_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include "data_struct.h"

namespace Ui {
class RecordCardNumber;
}

class RecordCardNumber : public QWidget
{
    Q_OBJECT

public:
    explicit RecordCardNumber(QWidget *parent = nullptr);
    ~RecordCardNumber();


signals:
    void saveCard_info(Card_info);

private slots:


    void on_readButton_clicked();

    void on_entryButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::RecordCardNumber *ui;
};

#endif // RECORDCARDNUMBER_H
