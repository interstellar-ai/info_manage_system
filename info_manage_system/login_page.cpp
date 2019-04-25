#include "login_page.h"
#include "ui_login_page.h"

Login_page::Login_page(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Login_page)
{
    ui->setupUi(this);
    set_button();
}

Login_page::~Login_page()
{
    delete ui;
}

void Login_page::set_button(){
    ui->okButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->cancelButton->setStyleSheet(
        "QPushButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:20px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QPushButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QPushButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}


void Login_page::on_cancelButton_clicked()
{
    QCoreApplication::exit();
}

void Login_page::on_okButton_clicked()
{
    if (ui->userName->text().isEmpty() || ui->password->text().isEmpty()){
        QMessageBox::information(this, "infor", "usrname or passwd cant be empty");
        return;
    }
    emit login_usr_passwd(ui->userName->text(), ui->password->text());
}
