#include "in_out_account_page.h"
#include "ui_in_out_account_page.h"

IN_OUT_ACCOUNT_PAGE::IN_OUT_ACCOUNT_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::IN_OUT_ACCOUNT_PAGE)
{
    ui->setupUi(this);
    init_in_out_account_page();
    set_pushButton();
}

IN_OUT_ACCOUNT_PAGE::~IN_OUT_ACCOUNT_PAGE()
{
    delete ui;
}

void IN_OUT_ACCOUNT_PAGE::set_pushButton(){
    ui->in_accountButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->out_accountButton->setStyleSheet(
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
    ui->uploadPhoto->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void IN_OUT_ACCOUNT_PAGE::init_in_out_account_page(){
    bool initialization = false;
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(initialization);
    ui->stu_class->setEnabled(initialization);
    ui->stu_indentification_number->setEnabled(initialization);
    ui->stu_status_of_student_status->setEnabled(initialization);
    ui->account_in_time->setEnabled(initialization);
    ui->account_out_time->setEnabled(initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
    ui->uploadPhoto->setEnabled(initialization);
}

void IN_OUT_ACCOUNT_PAGE::on_in_accountButton_clicked()
{
    index = 1;
    bool initialization = true;
    ui->out_accountButton->setEnabled(false);
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(initialization);
    ui->stu_class->setEnabled(initialization);
    ui->stu_indentification_number->setEnabled(initialization);
    ui->stu_status_of_student_status->setEnabled(initialization);
    ui->account_in_time->setEnabled(initialization);
    ui->account_out_time->setEnabled(!initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->searchButton->setEnabled(!initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->uploadPhoto->setEnabled(initialization);
    empty_lineEdit();
}

void IN_OUT_ACCOUNT_PAGE::on_out_accountButton_clicked()
{
    index = 2;
    bool initialization = true;
    ui->in_accountButton->setEnabled(false);
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(!initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(!initialization);
    ui->stu_class->setEnabled(!initialization);
    ui->stu_indentification_number->setEnabled(!initialization);
    ui->stu_status_of_student_status->setEnabled(!initialization);
    ui->account_in_time->setEnabled(!initialization);
    ui->account_out_time->setEnabled(!initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(!initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
    ui->uploadPhoto->setEnabled(!initialization);
    empty_lineEdit();
}


void IN_OUT_ACCOUNT_PAGE::on_write_concelButton_clicked()
{
    ui->stu_name->setEnabled(true);
    ui->stu_ID->setEnabled(true);
    ui->account_out_time->setEnabled(false);
    ui->out_accountButton->setEnabled(true);
    ui->in_accountButton->setEnabled(true);
//    restore_lineEdit_and_PushBuuton();
    empty_lineEdit();
}

void IN_OUT_ACCOUNT_PAGE::restore_lineEdit_and_PushBuuton(){
    init_in_out_account_page();
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
}

void IN_OUT_ACCOUNT_PAGE::on_searchButton_clicked()
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

void IN_OUT_ACCOUNT_PAGE::searchResult(Account_info account_info){
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
    QImage img;
    img.load(account_info.photoPath);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->write_OKButton->setEnabled(true);
    ui->account_out_time->setEnabled(true);
}

void IN_OUT_ACCOUNT_PAGE::on_write_OKButton_clicked()
{
    Account_info account_info;
    if (index == 1){
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
        account_info.photoPath = photoPath_;
        emit addAccount(account_info);
    }
    else if (index == 2){
        if (ui->account_out_time->text().isEmpty()){
            QMessageBox::warning(this, "警告", "信息不能为空");
            return;
        }
        account_info.account_out_time = ui->account_out_time->text();
        account_info.stu_ID = ui->stu_ID->text().toInt();
        emit addOutAccountTime(account_info);
    }
}

void IN_OUT_ACCOUNT_PAGE::on_uploadPhoto_clicked()
{
    QString photoPath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "/home",
                                                     tr("Images (*.png *.xpm *.jpg)"));
    if (photoPath == ""){
        return;
    }
    photoPath_ = photoPath;
    qDebug() << photoPath;
    QDateTime dtime;
    QFile file(photoPath);
    photoPath_ = "../photo/" + tr("%1").arg(dtime.currentSecsSinceEpoch()) + ".jpg";
    qDebug() << photoPath_;
    if(file.copy(photoPath_)){
        QMessageBox::information(this, "通知", "上传成功");
    }
    else {
        QMessageBox::warning(this, "警告", "上传失败");
    }
    QImage img;
    img.load(photoPath_);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void IN_OUT_ACCOUNT_PAGE::on_readCardButton_clicked()
{
    if (index == 2){
        QSerialPort serialPort;
        const QString serialPortName = "COM3";
        serialPort.setPortName(serialPortName);
        serialPort.setBaudRate(QSerialPort::Baud9600);

        if (!serialPort.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "警告", QObject::tr("Failed to open port %1, error: %2")
                    .arg(serialPortName).arg(serialPort.error()));
    //        QMessageBox::question(this, "请求", "请输入duan'kou端口号", )
            return;
        }
        while(!serialPort.waitForReadyRead());
        int readData = serialPort.readAll().toInt();
    //    int readData = serialPort.readAll().toInt();
        if (serialPort.error() == QSerialPort::ReadError) {
                QMessageBox::warning(this, "警告", QObject::tr("Failed to read from port %1, error: %2")
                                  .arg(serialPortName).arg(serialPort.errorString()));
                return;
        } else if (serialPort.error() == QSerialPort::TimeoutError && readData == 0) {
            QMessageBox::warning(this, "警告", QObject::tr("No data was currently available"
                                              " for reading from port %1").arg(serialPortName));
            return;
        }
    //    QMessageBox::warning(this, "警告", QObject::tr("Data successfully received from port %1")
    //                          .arg(serialPortName));
        Account_info account_info;
        account_info.stu_ID =readData;

        qDebug() << readData;
        serialPort.close();
        emit readStu_ID_info(account_info);
    }
}
