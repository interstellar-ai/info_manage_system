#include "account_card_borrow_page.h"
#include "ui_account_card_borrow_page.h"

ACCOUNT_CARD_BORROW_PAGE::ACCOUNT_CARD_BORROW_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ACCOUNT_CARD_BORROW_PAGE)
{
    ui->setupUi(this);
    set_pushButton();
    bool init = false;
    ui->stu_sex->setEnabled(init);
    ui->stu_name->setEnabled(init);
    ui->stu_college->setEnabled(init);
    ui->stu_class->setEnabled(init);
    ui->reason_2->setEnabled(init);
    ui->borrow_time_2->setEnabled(init);
    ui->tabWidget->setCurrentIndex(0);
    on_tabWidget_currentChanged(0);

}

ACCOUNT_CARD_BORROW_PAGE::~ACCOUNT_CARD_BORROW_PAGE()
{
    delete ui;
}

void ACCOUNT_CARD_BORROW_PAGE::set_pushButton(){
//    ui->okButton->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
//    ui->concelButton->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
//    ui->importButton->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
//    ui->readCardButton->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
//    ui->searchButton->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
//    ui->updateData->setStyleSheet(
//        "QPushButton{ background-color : rgb(85, 170, 255);"
//                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
//                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
//        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
//        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

bool ACCOUNT_CARD_BORROW_PAGE::isDate(QString date){
    QStringList list = date.split("-");
    if (list.size() != 3)
        return false;
    int md[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y = list[0].toInt();
    int m = list[1].toInt();
//    qDebug() << m;
    int d = list[2].toInt();
    md[1] = ((y%4 == 0 && y%100 != 0) || y%400==0) ? 29 : 28;//闰年调整
    if(y>0 && m>0 && m<13 && d>0 && d<=md[m-1])
        return true;
    else {
        return false;
    }
}

void ACCOUNT_CARD_BORROW_PAGE::empty_lineEdit(){
    ui->stu_ID->clear();
    ui->stu_sex->clear();
    ui->stu_name->clear();
    ui->stu_college->clear();
    ui->stu_class->clear();
    ui->reason->clear();
    ui->borrow_time->clear();
    ui->label->clear();
}

void ACCOUNT_CARD_BORROW_PAGE::empty_lineEdit_2(){
    ui->stu_ID_2->clear();
    ui->reason_2->clear();
    ui->borrow_time_2->clear();
    ui->return_time_2->clear();
    ui->label_2->clear();
}


void ACCOUNT_CARD_BORROW_PAGE::on_searchButton_clicked()
{
    if (ui->stu_ID->text().isEmpty()){
        QMessageBox::warning(this, "警告", "学号不能为空");
        return;
    }
    Account_info account_info;
    account_info.stu_ID = ui->stu_ID->text().toInt();
    emit inputNameAndStuId(account_info);

}

void ACCOUNT_CARD_BORROW_PAGE::searchResult_2(BorrowCard card){
    empty_lineEdit_2();
    ui->stu_ID_2->setEnabled(false);
    ui->stu_ID_2->setText(QString::number(card.stu_ID));
    ui->reason_2->setText(card.reason);
    ui->borrow_time_2->setText(card.borrowDate);
    ui->return_time_2->setEnabled(true);
    QImage img;
    img.load(card.photoPath);
    ui->label_2->setPixmap(QPixmap::fromImage(img));
    ui->okButton_2->setEnabled(true);
}

void ACCOUNT_CARD_BORROW_PAGE::searchResult(Account_info account_info){
    empty_lineEdit();
    ui->stu_ID->setEnabled(false);
    ui->stu_name->setText(account_info.stu_name);
    ui->stu_ID->setText(QString::number(account_info.stu_ID));
    ui->stu_sex->setText(account_info.stu_sex);
    ui->stu_college->setText(account_info.stu_college);
    ui->stu_class->setText(account_info.stu_class);
    QImage img;
    photoPath_ = account_info.photoPath;
    img.load(account_info.photoPath);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->reason->setEnabled(true);
    ui->borrow_time->setEnabled(true);
    ui->okButton->setEnabled(true);
}

void ACCOUNT_CARD_BORROW_PAGE::searchResult_4(Account_info account_info){
    searchResult(account_info);
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
    QString readData = serialPort.readAll();
    readData = readData.split("\r\n")[0];
//    qDebug() << readData;
    if (serialPort.error() == QSerialPort::ReadError) {
            QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to read from port %1, error: %2")
                              .arg(serialPortName).arg(serialPort.errorString()));
            return;
    } else if (serialPort.error() == QSerialPort::TimeoutError && readData == nullptr) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("No data was currently available"
                                          " for reading from port %1").arg(serialPortName));
        return;
    }
    Card_info card;
    card.card_ID = readData;
    serialPort.close();
    emit getCard_ID_1(card);
}

void ACCOUNT_CARD_BORROW_PAGE::on_tabWidget_currentChanged(int index)
{
//    index_ = index;
//    if (index == 0){
//        bool init = false;
//        ui->stu_ID->setEnabled(!init);

//        ui->reason->setEnabled(init);
//        ui->borrow_time->setEnabled(init);
//        ui->importButton->setEnabled(init);
//        ui->readCardButton->setEnabled(!init);
//        ui->searchButton->setEnabled(!init);
//        ui->updateData->setEnabled(init);
//        ui->okButton->setEnabled(init);
//    }
//    else {
//        bool init = false;
//        ui->stu_ID_2->setEnabled(!init);

//        ui->return_time_2->setEnabled(init);
//        ui->importButton_2->setEnabled(!init);
//        ui->readCardButton_2->setEnabled(!init);
//        ui->searchButton_2->setEnabled(!init);
//        ui->okButton_2->setEnabled(init);
//    }
}

void ACCOUNT_CARD_BORROW_PAGE::on_okButton_clicked()
{
    BorrowCard borwCard;
    if (ui->borrow_time->text().isEmpty()){
        QMessageBox::warning(this, "警告", "借取时间不能为空");
        return;
    }

    if (!isDate(ui->borrow_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    QStringList list = ui->borrow_time->text().split('-');
    if (list[1].size() == 1){
        list[1] = '0' + list[1];
    }
    if (list[2].size() == 1){
        list[2] = '0' + list[2];
    }
    borwCard.stu_ID = ui->stu_ID->text().toInt();
    borwCard.reason = ui->reason->text();
    borwCard.borrowDate = list[0] + list[1] + list[2];
    borwCard.photoPath = photoPath_;
    emit addBorrowDate(borwCard);
}

void ACCOUNT_CARD_BORROW_PAGE::on_okButton_2_clicked()
{
    BorrowCard borwCard;
    if (ui->return_time_2->text().isEmpty()){
        QMessageBox::warning(this, "警告", "归还时间不能为空");
        return;
    }
    if (!isDate(ui->return_time_2->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    QStringList list = ui->return_time_2->text().split('-');
    if (list[1].size() == 1){
        list[1] = '0' + list[1];
    }
    if (list[2].size() == 1){
        list[2] = '0' + list[2];
    }
    borwCard.stu_ID = ui->stu_ID_2->text().toInt();
    borwCard.borrowDate = ui->borrow_time_2->text();
    borwCard.backDate = list[0] + list[1] + list[2];
//    qDebug() << borwCard.backDate;
    emit addBackDate(borwCard);
}

void ACCOUNT_CARD_BORROW_PAGE::on_readCardButton_2_clicked()
{
    QSerialPort serialPort;
    const QString serialPortName = "COM3";
    serialPort.setPortName(serialPortName);
    serialPort.setBaudRate(QSerialPort::Baud9600);
    if (!serialPort.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to open port %1, error: %2")
                .arg(serialPortName).arg(serialPort.error()));
        return;
    }
    serialPort.waitForReadyRead(5000);
    QString readData = serialPort.readAll();
    readData = readData.split("\r\n")[0];
    if (serialPort.error() == QSerialPort::ReadError) {
            QMessageBox::warning(nullptr, "警告", QObject::tr("Failed to read from port %1, error: %2")
                              .arg(serialPortName).arg(serialPort.errorString()));
            return;
    } else if (serialPort.error() == QSerialPort::TimeoutError && readData == nullptr) {
        QMessageBox::warning(nullptr, "警告", QObject::tr("No data was currently available"
                                          " for reading from port %1").arg(serialPortName));
        return;
    }
    serialPort.close();
    Card_info card;
    card.card_ID = readData;
    emit getCard_ID_2(card);
}

void ACCOUNT_CARD_BORROW_PAGE::on_concelButton_clicked()
{
    photoPath_ = "";
    ui->stu_ID->setEnabled(true);
    ui->reason->setEnabled(false);
    ui->borrow_time->setEnabled(false);
    ui->okButton->setEnabled(false);
    empty_lineEdit();
}

void ACCOUNT_CARD_BORROW_PAGE::on_concelButton_2_clicked()
{
    photoPath_ = "";
    ui->stu_ID_2->setEnabled(true);
    ui->return_time_2->setEnabled(false);
    ui->okButton_2->setEnabled(false);
    empty_lineEdit_2();
}

void ACCOUNT_CARD_BORROW_PAGE::on_searchButton_2_clicked()
{
    if (ui->stu_ID_2->text().isEmpty()){
        QMessageBox::warning(this, "警告", "学号不能为空");
        return;
    }
    BorrowCard card;
    card.stu_ID = ui->stu_ID_2->text().toInt();
    emit searchBorrowTime(card);
}

void ACCOUNT_CARD_BORROW_PAGE::on_updateData_clicked(){

}

void ACCOUNT_CARD_BORROW_PAGE::on_importButton_2_clicked()
{
    on_importButton_clicked();
}

void ACCOUNT_CARD_BORROW_PAGE::on_importButton_clicked()
{
    QString excel = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "/home",
                                                 tr("Excel (*.xlsx *.xlsm *.xltx *.xltm *.xlsb *.xlam)"));
    if (excel != ""){
        emit borrow_record_import(excel);
    }
}
