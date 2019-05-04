#include "search_page.h"
#include "ui_search_page.h"

SEARCH_PAGE::SEARCH_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SEARCH_PAGE)
{
    ui->setupUi(this);
    set_pushuButton();
}

SEARCH_PAGE::~SEARCH_PAGE()
{
    delete ui;
}

void SEARCH_PAGE::set_pushuButton(){
    ui->searchButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->exportButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void SEARCH_PAGE::on_searchButton_clicked()
{
    Account_info account_info;
    account_info.stu_name = ui->stu_name->text();
    account_info.stu_ID = ui->stu_ID->text().toInt();
    account_info.stu_college = ui->stu_college->text();
    account_info.stu_class = ui->stu_class->text();
    account_info.stu_sex = ui->stu_sex->text();
    account_info.stu_indentification_number = ui->stu_indentification_number->text();
    account_info.stu_status_of_student_status = ui->stu_status_of_student_status->text();
    account_info.account_in_time = ui->account_in_time->text();
    account_info.account_out_time = ui->account_out_time->text();
    account_info.borrow_time = ui->borrow_time->text();
    account_info.return_time = ui->return_time->text();
    emit searchByMultiCodt(account_info);
    ui->textEdit->clear();
    QString col = "stu_name, stu_ID, stu_college, stu_class, stu_sex,"
                  "stu_indentification_number, stu_status_of_student_status,"
                  "account_in_time, account_out_time, borrow_time, return_time";
}

void SEARCH_PAGE::searchResult_mult(Account_info account_info){
    QString cont = account_info.stu_name + " "+
            QString::number(account_info.stu_ID) + " "+
            account_info.stu_college + account_info.stu_class + " "+
            account_info.stu_indentification_number + " "+
            account_info.stu_status_of_student_status + " "+
            account_info.account_in_time + " "+
            account_info.account_out_time + " "+
            account_info.borrow_time + " "+
            account_info.return_time;
    ui->textEdit->append(cont);
}
