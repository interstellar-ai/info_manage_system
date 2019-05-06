#include "account_card_borrow_page.h"
#include "ui_account_card_borrow_page.h"

ACCOUNT_CARD_BORROW_PAGE::ACCOUNT_CARD_BORROW_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ACCOUNT_CARD_BORROW_PAGE)
{
    ui->setupUi(this);
    init_in_out_account_page();
    set_pushButton();
}

ACCOUNT_CARD_BORROW_PAGE::~ACCOUNT_CARD_BORROW_PAGE()
{
    delete ui;
}

void ACCOUNT_CARD_BORROW_PAGE::init_in_out_account_page(){
    bool initialization = false;
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(initialization);
    ui->stu_class->setEnabled(initialization);
    ui->stu_indentification_number->setEnabled(initialization);
    ui->borrow_time->setEnabled(initialization);
    ui->return_time->setEnabled(initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
    ui->updateData->setEnabled(initialization);
}

void ACCOUNT_CARD_BORROW_PAGE::set_pushButton(){
    ui->borrowButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->returnButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->write_OKButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->write_concelButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->importButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->readCardButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->searchButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->updateData->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void ACCOUNT_CARD_BORROW_PAGE::on_borrowButton_clicked()
{
    index = 1;
    bool init = false;
    ui->stu_name->setEnabled(!init);
    ui->stu_ID->setEnabled(!init);
    ui->returnButton->setEnabled(false);
    ui->stu_sex->setEnabled(init);
    ui->stu_college->setEnabled(init);
    ui->stu_class->setEnabled(init);
    ui->stu_indentification_number->setEnabled(init);
    ui->borrow_time->setEnabled(init);
    ui->return_time->setEnabled(init);
    ui->importButton->setEnabled(init);
    ui->write_OKButton->setEnabled(init);
    ui->write_concelButton->setEnabled(!init);
    ui->readCardButton->setEnabled(!init);
    ui->searchButton->setEnabled(!init);
    ui->updateData->setEnabled(!init);
    empty_lineEdit();
}

void ACCOUNT_CARD_BORROW_PAGE::empty_lineEdit(){
    ui->stu_ID->clear();
    ui->stu_sex->clear();
    ui->stu_name->clear();
    ui->stu_college->clear();
    ui->stu_class->clear();
    ui->stu_indentification_number->clear();
    ui->borrow_time->clear();
    ui->return_time->clear();
    ui->label->clear();
}

void ACCOUNT_CARD_BORROW_PAGE::on_returnButton_clicked()
{
    index = 2;
    bool init = false;
    ui->stu_name->setEnabled(!init);
    ui->stu_ID->setEnabled(!init);
    ui->stu_sex->setEnabled(init);
    ui->returnButton->setEnabled(false);
    ui->stu_college->setEnabled(init);
    ui->stu_class->setEnabled(init);
    ui->stu_indentification_number->setEnabled(init);
    ui->borrow_time->setEnabled(init);
    ui->return_time->setEnabled(init);
    ui->importButton->setEnabled(init);
    ui->write_OKButton->setEnabled(init);
    ui->write_concelButton->setEnabled(!init);
    ui->readCardButton->setEnabled(!init);
    ui->searchButton->setEnabled(!init);
    ui->updateData->setEnabled(!init);
    empty_lineEdit();
}


void ACCOUNT_CARD_BORROW_PAGE::restore_lineEdit_and_PushBuuton(){
    init_in_out_account_page();
}

void ACCOUNT_CARD_BORROW_PAGE::on_searchButton_clicked()
{
    if (ui->stu_name->text().isEmpty() || ui->stu_ID->text().isEmpty()){
        QMessageBox::warning(this, "警告", "姓名/学号不能为空");
        return;
    }
    Account_info account_info;
    account_info.stu_name = ui->stu_name->text();
    account_info.stu_ID = ui->stu_ID->text().toInt();
    emit inputNameAndStuId(account_info);

}

void ACCOUNT_CARD_BORROW_PAGE::searchResult(Account_info account_info){
    ui->stu_name->setEnabled(false);
    ui->stu_ID->setEnabled(false);
    ui->stu_name->setText(account_info.stu_name);
    ui->stu_ID->setText(QString::number(account_info.stu_ID));
//    qDebug() << QString::number(account_info.stu_ID);
    ui->stu_sex->setText(account_info.stu_sex);
    ui->stu_college->setText(account_info.stu_college);
    ui->stu_class->setText(account_info.stu_class);
    ui->stu_indentification_number->setText(account_info.stu_indentification_number);
    ui->borrow_time->setText(account_info.borrow_time);
    ui->return_time->setText(account_info.return_time);
    QImage img;
    img.load(account_info.photoPath);
    ui->label->setPixmap(QPixmap::fromImage(img));
    if (index == 1){
        if (ui->borrow_time->text().isEmpty()){
            ui->write_OKButton->setEnabled(true);
            ui->borrow_time->setEnabled(true);
        }
    }
    else if (index == 2){
        if (ui->return_time->text().isEmpty()){
            ui->write_OKButton->setEnabled(true);
            ui->return_time->setEnabled(true);
        }
    }
    else if (index == 3) {
        ui->borrow_time->setEnabled(true);
        ui->return_time->setEnabled(true);
        ui->write_OKButton->setEnabled(true);
//        ui->write_concelButton->setEnabled(true);
    }
}

void ACCOUNT_CARD_BORROW_PAGE::on_write_concelButton_clicked()
{
    ui->borrowButton->setEnabled(true);
    ui->returnButton->setEnabled(true);
    ui->stu_name->setEnabled(true);
    ui->stu_ID->setEnabled(true);
    ui->borrow_time->setEnabled(false);
    ui->return_time->setEnabled(false);
    empty_lineEdit();
}

void ACCOUNT_CARD_BORROW_PAGE::on_write_OKButton_clicked()
{
    Account_info account_info;
    if (ui->borrow_time->text().isEmpty() && index == 1){
        QMessageBox::warning(this, "警告", "信息不能为空");
        return;
    }
    if (ui->return_time->text().isEmpty() && index == 2){
        QMessageBox::warning(this, "警告", "信息不能为空");
        return;
    }
    account_info.borrow_time = ui->borrow_time->text();
    account_info.return_time = ui->return_time->text();
    account_info.stu_ID = ui->stu_ID->text().toInt();
    emit addTime(account_info);
}

void ACCOUNT_CARD_BORROW_PAGE::on_readCardButton_clicked()
{
    QSerialPort serialPort;
    const QString serialPortName = "COM3";
    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(QSerialPort::Baud9600);
    if (!serialPort.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to open port %1, error: %2")
                .arg(serialPortName).arg(serialPort.error()));
//        QMessageBox::question(this, "请求", "请输入duan'kou端口号", )
        return;
    }
    serialPort.waitForReadyRead(5000);
    int readData = serialPort.readAll().toInt();
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
    Account_info account_info;
    account_info.stu_ID = readData;
    qDebug() << readData;
    serialPort.close();
    emit readStu_ID_info(account_info);
}

void ACCOUNT_CARD_BORROW_PAGE::on_updateData_clicked()
{
    index = 3;
    bool init = false;
    ui->stu_name->setEnabled(!init);
    ui->stu_ID->setEnabled(!init);
    ui->stu_sex->setEnabled(init);
    ui->stu_college->setEnabled(init);
    ui->stu_class->setEnabled(init);
    ui->stu_indentification_number->setEnabled(init);
    ui->borrow_time->setEnabled(init);
    ui->return_time->setEnabled(init);
    ui->importButton->setEnabled(init);
    ui->write_OKButton->setEnabled(init);
    ui->write_concelButton->setEnabled(!init);
    ui->readCardButton->setEnabled(!init);
    ui->searchButton->setEnabled(!init);
    ui->updateData->setEnabled(!init);
    empty_lineEdit();
}
