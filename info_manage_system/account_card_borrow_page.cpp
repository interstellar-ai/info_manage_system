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
    ui->uploadPhoto->setEnabled(initialization);
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
    ui->uploadPhoto->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void ACCOUNT_CARD_BORROW_PAGE::on_borrowButton_clicked()
{
    bool initialization = true;
    ui->returnButton->setEnabled(false);
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(initialization);
    ui->stu_class->setEnabled(initialization);
    ui->stu_indentification_number->setEnabled(initialization);
    ui->borrow_time->setEnabled(initialization);
    ui->return_time->setEnabled(!initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(!initialization);
    ui->uploadPhoto->setEnabled(initialization);
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
}

void ACCOUNT_CARD_BORROW_PAGE::on_returnButton_clicked()
{
    bool initialization = true;
    ui->borrowButton->setEnabled(false);
    ui->stu_ID->setEnabled(initialization);
    ui->stu_sex->setEnabled(!initialization);
    ui->stu_name->setEnabled(initialization);
    ui->stu_college->setEnabled(!initialization);
    ui->stu_class->setEnabled(!initialization);
    ui->stu_indentification_number->setEnabled(!initialization);
    ui->borrow_time->setEnabled(!initialization);
    ui->return_time->setEnabled(!initialization);
    ui->importButton->setEnabled(initialization);
    ui->write_OKButton->setEnabled(!initialization);
    ui->write_concelButton->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
    ui->uploadPhoto->setEnabled(!initialization);
    empty_lineEdit();
}


void ACCOUNT_CARD_BORROW_PAGE::restore_lineEdit_and_PushBuuton(){
    init_in_out_account_page();
}

void ACCOUNT_CARD_BORROW_PAGE::on_searchButton_clicked()
{
    ui->write_OKButton->setEnabled(true);
    ui->return_time->setEnabled(true);
}

void ACCOUNT_CARD_BORROW_PAGE::on_write_concelButton_clicked()
{
    ui->borrowButton->setEnabled(true);
    ui->returnButton->setEnabled(true);
    restore_lineEdit_and_PushBuuton();
    empty_lineEdit();
}
