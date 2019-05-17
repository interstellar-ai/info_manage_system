#include "searchpage.h"
#include "ui_searchpage.h"

SearchPage::SearchPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchPage)
{
    ui->setupUi(this);
}

SearchPage::~SearchPage()
{
    delete ui;
}

void SearchPage::on_searchButton_clicked()
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

    BorrowCard card;
    card.stu_ID = ui->stu_ID->text().toInt();
    card.reason = ui->reason->text();
    card.borrowDate = ui->borrow_time->text();
    card.backDate = ui->return_time->text();

    if (!ui->account_in_time->text().isEmpty() && !isDate(ui->account_in_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    if (!ui->account_out_time->text().isEmpty() && !isDate(ui->account_out_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    if (!ui->borrow_time->text().isEmpty() && !isDate(ui->borrow_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }
    if (!ui->return_time->text().isEmpty() && !isDate(ui->return_time->text())){
        QMessageBox::warning(this, "警告", "日期格式错误");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(12);
    QStringList strList;
    strList << "姓名" << "学号" << "学院" << "班级" << "性别" << "身份号码" << "学籍情况"
            << "入户时间" << "出户时间" << "借卡原因" << "借卡时间" << "还卡时间";
    ui->tableWidget->setHorizontalHeaderLabels(strList);
    rowCur = 0;

    emit searchByMultiCodt(account_info, card);
}

void SearchPage::searchResult_m(Account_info account, BorrowCard card){
    ui->tableWidget->insertRow(rowCur);
    ui->tableWidget->setItem(rowCur, 0, new QTableWidgetItem(account.stu_name));
    ui->tableWidget->setItem(rowCur, 1, new QTableWidgetItem(QString::number(account.stu_ID)));
    ui->tableWidget->setItem(rowCur, 2, new QTableWidgetItem(account.stu_college));
    ui->tableWidget->setItem(rowCur, 3, new QTableWidgetItem(account.stu_class));
    ui->tableWidget->setItem(rowCur, 4, new QTableWidgetItem(account.stu_sex));
    ui->tableWidget->setItem(rowCur, 5, new QTableWidgetItem(account.stu_indentification_number));
    ui->tableWidget->setItem(rowCur, 6, new QTableWidgetItem(account.stu_status_of_student_status));
    ui->tableWidget->setItem(rowCur, 7, new QTableWidgetItem(account.account_in_time));
    ui->tableWidget->setItem(rowCur, 8, new QTableWidgetItem(account.account_out_time));
    ui->tableWidget->setItem(rowCur, 9, new QTableWidgetItem(card.reason));
    ui->tableWidget->setItem(rowCur, 10, new QTableWidgetItem(card.borrowDate));
    ui->tableWidget->setItem(rowCur, 11, new QTableWidgetItem(card.backDate));
    ++rowCur;
}


void SearchPage::on_exportButton_clicked()
{

}

bool SearchPage::isDate(QString date){
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
