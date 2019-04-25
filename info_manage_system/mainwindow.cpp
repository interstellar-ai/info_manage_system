/*********************************************************************************/
/*
 * 数据库创建 出入户 表
 * create table account_in_out(
 *  stu_name varchar(20) not null, stu_ID int primary key,
 *  stu_college varchar(20) not null, stu_class varchar(20) not null,
 *  stu_sex varchar(1) not null, stu_indentification_number varchar(18) not null,
 *  stu_status_of_student_status varchar(20) not null,
 *  account_in_time  varchar(20) not null, account_out_time varchar(20),
 *  photoPath varchar(50));
 * 查看表属性
 * show columns from account_in_out;
*/
/*********************************************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("info_manage_system");
    setWindowState(Qt::WindowMaximized);
    set_pushButton();
    ui->in_out_account->setEnabled(false);
    ui->account_card_borrow->setEnabled(false);
    ui->search->setEnabled(false);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    connect(ui->log_in_page, &Login_page::login_usr_passwd,
            this, &MainWindow::connect_database);
    connect(ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::addAccount,
            this, &MainWindow::addAccount);
}

void MainWindow::connect_database(QString usr, QString passwd){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql");
//    db.setUserName("root");
//    db.setPassword("root");
    db.setUserName(usr);
    db.setPassword(passwd);
    bool ok = db.open();
    if (!ok){
        QMessageBox::information(this, "infor", "connect failed username or passward error");
        return;
    }
    else {
        qDebug() << "success";
    }
    restoreToolButton();
    qsQuery = QSqlQuery(db);
//    QString strSqlText("SELECT * FROM user");//查询语法
//    qsQuery.prepare(strSqlText);
//    qsQuery.exec();
//    qDebug() << qsQuery.result();
}

void MainWindow::addAccount(Account account){
    qsQuery.prepare("INSERT INTO account_in_out (stu_name, stu_ID, stu_college,"
                    "stu_class, stu_sex, stu_indentification_number,"
                    "stu_status_of_student_status, account_in_time,"
                    "account_out_time, photoPath)"
                    "VALUES (:stu_name, :stu_ID, :stu_college,"
                    ":stu_class, :stu_sex, :stu_indentification_number,"
                    ":stu_status_of_student_status, :account_in_time,"
                    ":account_out_time, :photoPath)");
    qsQuery.bindValue(":stu_name", account.stu_name);
    qsQuery.bindValue(":stu_ID", account.stu_ID);
    qsQuery.bindValue(":stu_college", account.stu_college);
    qsQuery.bindValue(":stu_class", account.stu_class);
    qsQuery.bindValue(":stu_sex", account.stu_sex);
    qsQuery.bindValue(":stu_indentification_number", account.stu_indentification_number);
    qsQuery.bindValue(":stu_status_of_student_status", account.stu_status_of_student_status);
    qsQuery.bindValue(":account_in_time", account.account_in_time);
    qsQuery.bindValue(":account_out_time", account.account_out_time);
    qsQuery.bindValue(":photoPath", account.photoPath);
    if (qsQuery.exec()){
        QMessageBox::information(this, "info", "insert successfully");
    }
    else {
        QSqlError error(qsQuery.lastError());
        QMessageBox::information(this, "info", error.text());
    }
}

void MainWindow::restoreToolButton(){
    ui->in_out_account->setEnabled(true);
    ui->account_card_borrow->setEnabled(true);
    ui->search->setEnabled(true);
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
}
void MainWindow::set_pushButton(){
    ui->in_out_account->setStyleSheet(
        "QToolButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QToolButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");

    ui->account_card_borrow->setStyleSheet(
        "QToolButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QToolButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
    ui->search->setStyleSheet(
        "QToolButton{ background-color : rgb(85, 170, 255);"
                "border:2px groove gray;border-radius:30px;padding:2px 4px;"
                "border-width: 3px;border-style: solid;border-color: darkblue;}" // 按键本色
        "QToolButton:hover{background-color:rgb(135, 203, 255);}"  // 鼠标停放时的色彩
        "QToolButton:pressed{background-color:rgb(85, 0, 255); border-style: inset; }");
}

void MainWindow::on_in_out_account_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
}

void MainWindow::on_account_card_borrow_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
}

void MainWindow::on_search_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);
}

void MainWindow::closeEvent(QCloseEvent *event){
    db.close();
    event->accept();
}
