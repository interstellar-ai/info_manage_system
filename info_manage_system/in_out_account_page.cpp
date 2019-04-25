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
    ui->readCardButton->setEnabled(initialization);
    ui->uploadPhoto->setEnabled(initialization);
    empty_lineEdit();
}

void IN_OUT_ACCOUNT_PAGE::on_out_accountButton_clicked()
{
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
}

void IN_OUT_ACCOUNT_PAGE::on_searchButton_clicked()
{
    ui->write_OKButton->setEnabled(true);
    ui->account_out_time->setEnabled(true);
}

void IN_OUT_ACCOUNT_PAGE::on_write_OKButton_clicked()
{
    Account account;
    account.stu_name = ui->stu_name->text();
    account.stu_ID = ui->stu_ID->text().toInt();
    account.stu_college = ui->stu_college->text();
    account.stu_class = ui->stu_class->text();
    account.stu_sex = ui->stu_sex->text();
    account.stu_indentification_number = ui->stu_indentification_number->text();
    account.stu_status_of_student_status = ui->stu_status_of_student_status->text();
    account.account_in_time = ui->account_in_time->text();
    account.account_out_time = ui->account_out_time->text();
    account.photoPath = photoPath_;
    emit addAccount(account);
}

void IN_OUT_ACCOUNT_PAGE::on_uploadPhoto_clicked()
{
    QString photoPath;
    photoPath_ = photoPath;
}
