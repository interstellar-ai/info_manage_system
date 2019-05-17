#include "in_out_account_page.h"
#include "ui_in_out_account_page.h"

IN_OUT_ACCOUNT_PAGE::IN_OUT_ACCOUNT_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::IN_OUT_ACCOUNT_PAGE)
{
    ui->setupUi(this);
    set_pushButton();
    ui->tabWidget->setCurrentIndex(0);
}

IN_OUT_ACCOUNT_PAGE::~IN_OUT_ACCOUNT_PAGE()
{
    delete ui;
}

void IN_OUT_ACCOUNT_PAGE::set_pushButton(){
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
    ui->uploadPhoto->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void IN_OUT_ACCOUNT_PAGE::empty_lineEdit(){
    ui->stu_ID->clear();
    ui->stu_sex->clear();
    ui->stu_name->clear();
    ui->stu_college->clear();
    ui->stu_class->clear();
    ui->stu_indentification_number->clear();
    ui->stu_status_of_student_status->clear();
    ui->account_in_time->clear();
    ui->account_out_time->clear();
    ui->label->clear();
    photoPath_ = "";
}

void IN_OUT_ACCOUNT_PAGE::empty_lineEdit_2(){
    ui->stu_ID_2->clear();
    ui->stu_sex_2->clear();
    ui->stu_name_2->clear();
    ui->stu_college_2->clear();
    ui->stu_class_2->clear();
    ui->stu_indentification_number_2->clear();
    ui->stu_status_of_student_status_2->clear();
    ui->account_in_time_2->clear();
    ui->account_out_time_2->clear();
    ui->label_2->clear();
}

void IN_OUT_ACCOUNT_PAGE::on_searchButton_clicked()
{
    if (ui->stu_ID_2->text().isEmpty()){
        QMessageBox::warning(this, "警告", "学号不能为空");
        return;
    }
    Account_info account_info;
    account_info.stu_ID = ui->stu_ID_2->text().toInt();
    emit inputNameAndStuId(account_info);
}

void IN_OUT_ACCOUNT_PAGE::searchResult(Account_info account_info){
    if (index_ == 0){
        ui->stu_name->setEnabled(false);
        ui->stu_ID->setEnabled(false);
        ui->stu_name->setText(account_info.stu_name);
        ui->stu_ID->setText(QString::number(account_info.stu_ID));
    //    qDebug() << QString::number(account_info.stu_ID);
        ui->stu_sex->setText(account_info.stu_sex);
        ui->stu_college->setText(account_info.stu_college);
        ui->stu_class->setText(account_info.stu_class);
        ui->stu_indentification_number->setText(account_info.stu_indentification_number);
        ui->stu_status_of_student_status->setText(account_info.stu_status_of_student_status);
        ui->account_in_time->setText(account_info.account_in_time);
        ui->account_out_time->setText(account_info.account_out_time);
        QImage img;
        img.load(account_info.photoPath);
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->account_out_time->setEnabled(true);
    }
    else {
        ui->stu_ID_2->setEnabled(false);
        ui->stu_name_2->setText(account_info.stu_name);
        ui->stu_ID_2->setText(QString::number(account_info.stu_ID));
    //    qDebug() << QString::number(account_info.stu_ID);
        ui->stu_sex_2->setText(account_info.stu_sex);
        ui->stu_college_2->setText(account_info.stu_college);
        ui->stu_class_2->setText(account_info.stu_class);
        ui->stu_indentification_number_2->setText(account_info.stu_indentification_number);
        ui->stu_status_of_student_status_2->setText(account_info.stu_status_of_student_status);
        ui->account_in_time_2->setText(account_info.account_in_time);
        QImage img;
        img.load(account_info.photoPath);
        ui->label_2->setPixmap(QPixmap::fromImage(img));
        ui->account_out_time_2->setEnabled(true);
        ui->okButton_2->setEnabled(true);
    }

}

void IN_OUT_ACCOUNT_PAGE::on_uploadPhoto_clicked()
{
    QString photoPath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/home",
                                                     tr("Images (*.png *.jpg)"));
    if (photoPath == ""){
        photoPath_ = "";
        return;
    }
    photoPath_ = photoPath;
    qDebug() << photoPath;
    QFile file(photoPath);
    if (ui->stu_ID->text().isEmpty()){
        QMessageBox::warning(this, "警告", "学号不能为空");
        return;
    }
    photoPath_ = "../photo/" + ui->stu_ID->text() + ".jpg";
//    qDebug() << photoPath_;
    if(file.copy(photoPath_)){
        QMessageBox::information(this, "通知", "上传成功");
    }
    else {
        QMessageBox::warning(this, "警告", "上传失败");
        return;
    }
    QImage img;
    img.load(photoPath_);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void IN_OUT_ACCOUNT_PAGE::on_readCardButton_clicked()
{

}

void IN_OUT_ACCOUNT_PAGE::on_tabWidget_currentChanged(int index)
{
    index_ = index;
    if (index == 0){
        ui->account_out_time->setEnabled(false);
    }
    else {
        bool init = false;
        ui->stu_name_2->setEnabled(init);
        ui->stu_sex_2->setEnabled(init);
        ui->stu_college_2->setEnabled(init);
        ui->stu_class_2->setEnabled(init);
        ui->stu_indentification_number_2->setEnabled(init);
        ui->stu_status_of_student_status_2->setEnabled(init);
        ui->account_in_time_2->setEnabled(init);
        ui->account_out_time_2->setEnabled(init);
        ui->okButton_2->setEnabled(init);
    }
}

void IN_OUT_ACCOUNT_PAGE::on_readCardButton_2_clicked()
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
    Card_info card;
    card.card_ID = readData;
    qDebug() << readData;
    serialPort.close();
    emit getCard_ID(card);
}


void IN_OUT_ACCOUNT_PAGE::on_concelButton_clicked()
{
    empty_lineEdit();
}

void IN_OUT_ACCOUNT_PAGE::on_concelButton_2_clicked()
{
    ui->stu_ID_2->setEnabled(true);
    ui->account_out_time_2->setEnabled(false);
    empty_lineEdit_2();
}

void IN_OUT_ACCOUNT_PAGE::on_okButton_clicked()
{
    Account_info account_info;
    if (ui->stu_name->text().isEmpty() || ui->stu_ID->text().isEmpty() ||
            ui->stu_college->text().isEmpty() || ui->stu_class->text().isEmpty() ||
            ui->stu_sex->text().isEmpty() || ui->stu_indentification_number->text().isEmpty()||
            ui->account_in_time->text().isEmpty()){
        QMessageBox::warning(this, "警告", "信息不能为空");
        return;
    }
    account_info.stu_name = ui->stu_name->text();
    account_info.stu_ID = ui->stu_ID->text().toInt();
    account_info.stu_college = ui->stu_college->text();
    account_info.stu_class = ui->stu_class->text();
    account_info.stu_sex = ui->stu_sex->text();
    account_info.stu_indentification_number = ui->stu_indentification_number->text();
    account_info.stu_status_of_student_status = ui->stu_status_of_student_status->text();
    account_info.account_in_time = ui->account_in_time->text();
    if (!isDate(ui->account_in_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    account_info.photoPath = photoPath_;
    emit addAccount(account_info);
}

void IN_OUT_ACCOUNT_PAGE::on_okButton_2_clicked()
{
    Account_info account_info;
    if (ui->account_out_time_2->text().isEmpty()){
        QMessageBox::warning(this, "警告", "信息不能为空");
        return;
    }
    account_info.stu_ID = ui->stu_ID_2->text().toInt();
    account_info.account_out_time = ui->account_out_time_2->text();
    if (!isDate(ui->account_out_time_2->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    if (ui->account_out_time_2->text() < ui->account_in_time_2->text()){
        QMessageBox::warning(this, "警告", "出户时间不能比入户时间早");
        return;
    }
    emit addOutAccountTime(account_info);
}

bool IN_OUT_ACCOUNT_PAGE::isDate(QString date){
    QStringList list = date.split("-");
    if (list.size() != 3)
        return false;
    int md[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int y = list[0].toInt();
    int m = list[1].toInt();
    int d = list[2].toInt();
    md[1] = ((y%4 == 0 && y%100 != 0) || y%400==0) ? 29 : 28;//闰年调整
    if(y>0 && m>0 && m<13 && d>0 && d<=md[m-1])
        return true;
    else {
        return false;
    }
}
