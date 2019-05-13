#include "recordcardnumber.h"
#include "ui_recordcardnumber.h"

RecordCardNumber::RecordCardNumber(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordCardNumber)
{
    ui->setupUi(this);
}

RecordCardNumber::~RecordCardNumber()
{
    delete ui;
}



void RecordCardNumber::on_readButton_clicked()
{
    ui->card_ID_edit->clear();
    QSerialPort serialPort;
    const QString serialPortName = "COM3";
    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(QSerialPort::Baud9600);
    if (!serialPort.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to open port %1, error: %2")
                .arg(serialPortName).arg(serialPort.error()));
//        QMessageBox::question(this, "请求", "请输入端口号", )
        return;
    }
    serialPort.waitForReadyRead(5000);
    QString readData = serialPort.readAll();
//    int readData = serialPort.readAll().toInt();
    if (serialPort.error() == QSerialPort::ReadError) {
            QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to read from port %1, error: %2")
                              .arg(serialPortName).arg(serialPort.errorString()));
            return;
    } else if (serialPort.error() == QSerialPort::TimeoutError && readData == 0) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("No data was currently available"
                                          " for reading from port %1").arg(serialPortName));
        return;
    }
//    QMessageBox::warning(this, "警告", QObject::tr("Data successfully received from port %1")
//                          .arg(serialPortName));
//    Card_info card_info;
//    card_info.card_ID = readData;
    ui->card_ID_edit->setText(readData);
//    qDebug() << readData;
    serialPort.close();
//    emit card_ID_s(card_info);
}

void RecordCardNumber::on_entryButton_clicked()
{
    if (ui->card_ID_edit->text().isEmpty() ||
            ui->stu_ID_edit->text().isEmpty()){
        QMessageBox::warning(nullptr, "警告", "不可为空");
        return;
    }
    Card_info card_info;
    card_info.card_ID = ui->card_ID_edit->text();
    card_info.stu_ID = ui->stu_ID_edit->text().toInt();
    emit saveCard_info(card_info);
}

void RecordCardNumber::on_clearButton_clicked()
{
    ui->card_ID_edit->clear();
    ui->stu_ID_edit->clear();
}
