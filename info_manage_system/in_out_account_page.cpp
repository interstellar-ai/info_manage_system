#include "in_out_account_page.h"
#include "ui_in_out_account_page.h"

IN_OUT_ACCOUNT_PAGE::IN_OUT_ACCOUNT_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::IN_OUT_ACCOUNT_PAGE)
{
    ui->setupUi(this);
    init_in_out_account_page();
}

IN_OUT_ACCOUNT_PAGE::~IN_OUT_ACCOUNT_PAGE()
{
    delete ui;
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
    empty_lineEdit();
}


void IN_OUT_ACCOUNT_PAGE::on_write_concelButton_clicked()
{
    ui->out_accountButton->setEnabled(true);
    ui->in_accountButton->setEnabled(true);
    restore_lineEdit_and_PushBuuton();
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
}
