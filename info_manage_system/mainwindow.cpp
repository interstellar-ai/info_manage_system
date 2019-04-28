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

    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage1);
    connect_database_();
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
    connect(ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::inputNameAndStuId,
            this, &MainWindow::searchStuInfo);
    connect(this, &MainWindow::searchResult,
            ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::searchResult);
    connect(ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::addOutAccountTime,
            this, &MainWindow::addOutAccountTime);
    createDir();
}



void MainWindow::connect_database_(){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("root");
//    db.setUserName(usr);
//    db.setPassword(passwd);
    bool ok = db.open();
    if (!ok){
        QMessageBox::warning(this, "警告", "username or password error");
        return;
    }
    restoreToolButton();
    qsQuery = QSqlQuery(db);
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
        QMessageBox::warning(this, "警告", "username or password error");
        return;
    }
    restoreToolButton();
    qsQuery = QSqlQuery(db);
}

void MainWindow::addAccount(Account_info account_info){
    qsQuery.prepare("INSERT INTO account_in_out (stu_name, stu_ID, stu_college,"
                    "stu_class, stu_sex, stu_indentification_number,"
                    "stu_status_of_student_status, account_in_time,"
                    "account_out_time, photoPath)"
                    "VALUES (:stu_name, :stu_ID, :stu_college,"
                    ":stu_class, :stu_sex, :stu_indentification_number,"
                    ":stu_status_of_student_status, :account_in_time,"
                    ":account_out_time, :photoPath)");
    qsQuery.bindValue(":stu_name", account_info.stu_name);
    qsQuery.bindValue(":stu_ID", account_info.stu_ID);
    qsQuery.bindValue(":stu_college", account_info.stu_college);
    qsQuery.bindValue(":stu_class", account_info.stu_class);
    qsQuery.bindValue(":stu_sex", account_info.stu_sex);
    qsQuery.bindValue(":stu_indentification_number", account_info.stu_indentification_number);
    qsQuery.bindValue(":stu_status_of_student_status", account_info.stu_status_of_student_status);
    qsQuery.bindValue(":account_in_time", account_info.account_in_time);
//    qsQuery.bindValue(":account_out_time", account_info.account_out_time);
    qsQuery.bindValue(":photoPath", account_info.photoPath);
    if (qsQuery.exec()){
        QMessageBox::information(this, "通知", "添加成功");
    }
    else {
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
    }
}

void MainWindow::searchStuInfo(Account_info account_info){
    qsQuery.prepare("select * from account_in_out where stu_ID = :stu_ID_");
    qsQuery.bindValue(":stu_ID_", account_info.stu_ID);
    if (!qsQuery.exec()){
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
        return;
    }
    if(qsQuery.first()){ // result is not empty
        if (qsQuery.value("stu_name").toString() == account_info.stu_name){
            account_info.stu_college = qsQuery.value("stu_college").toString();
            account_info.stu_class = qsQuery.value("stu_class").toString();
            account_info.stu_sex = qsQuery.value("stu_class").toString();
            account_info.stu_indentification_number = qsQuery.value("stu_indentification_number").toString();
            account_info.stu_status_of_student_status = qsQuery.value("stu_status_of_student_status").toString();
            account_info.account_in_time = qsQuery.value("account_in_time").toString();
            account_info.photoPath = qsQuery.value("photoPath").toString();
            emit searchResult(account_info);
        }
        else{
            QMessageBox::warning(this, "警告", "输入姓名和学号不匹配");
        }
    }
    else {
        QMessageBox::warning(this, "警告", "查无此人");
    }
}

void MainWindow::addOutAccountTime(Account_info account_info){
    qsQuery.prepare("update account_in_out set account_out_time = :account_out_time_ where stu_ID = :stu_ID_");
    qsQuery.bindValue(":account_out_time_", account_info.account_out_time);
    qsQuery.bindValue(":stu_ID_", account_info.stu_ID);
    qDebug() << account_info.stu_ID;
    qDebug() << account_info.account_out_time;
    if (!qsQuery.exec()){
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
        return;
    }
    else {
        QMessageBox::information(this, "通知", "添加成功");
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

void MainWindow::createDir(){
    QDir tempDir;
    if (!tempDir.exists("..//photo")){
        tempDir.mkdir("..//photo");
    }
}
