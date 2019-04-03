#include "account_card_borrow_page.h"
#include "ui_account_card_borrow_page.h"

ACCOUNT_CARD_BORROW_PAGE::ACCOUNT_CARD_BORROW_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ACCOUNT_CARD_BORROW_PAGE)
{
    ui->setupUi(this);
    init_in_out_account_page();
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
    ui->write_concel_Button->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
}

void ACCOUNT_CARD_BORROW_PAGE::on_borrowButton_clicked()
{
    bool initialization = true;
    ui->returnButton->setEnabled(false);
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
    ui->write_concel_Button->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
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
    ui->write_concel_Button->setEnabled(initialization);
    ui->readCardButton->setEnabled(initialization);
    ui->searchButton->setEnabled(initialization);
    empty_lineEdit();
}

void ACCOUNT_CARD_BORROW_PAGE::on_write_concel_Button_clicked()
{
    ui->borrowButton->setEnabled(true);
    ui->returnButton->setEnabled(true);
    restore_lineEdit_and_PushBuuton();
    empty_lineEdit();
}

void ACCOUNT_CARD_BORROW_PAGE::restore_lineEdit_and_PushBuuton(){
    init_in_out_account_page();
}

void ACCOUNT_CARD_BORROW_PAGE::on_searchButton_clicked()
{
    ui->write_OKButton->setEnabled(true);
}
