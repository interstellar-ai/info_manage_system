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
    createMySQL_Table();
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
    connect(ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::readStu_ID_info,
            this, &MainWindow::readStu_ID_info);
    connect(ui->account_card_borrow_page, &ACCOUNT_CARD_BORROW_PAGE::inputNameAndStuId,
            this, &MainWindow::searchStuInfo);
    connect(this, &MainWindow::searchResult,
            ui->account_card_borrow_page, &ACCOUNT_CARD_BORROW_PAGE::searchResult);
    connect(ui->account_card_borrow_page, &ACCOUNT_CARD_BORROW_PAGE::readStu_ID_info,
            this, &MainWindow::readStu_ID_info);
    connect(ui->account_card_borrow_page, &ACCOUNT_CARD_BORROW_PAGE::addTime,
            this, &MainWindow::addTime);
    connect(this, &MainWindow::empty_lineEdit,
            ui->in_out_account_page, &IN_OUT_ACCOUNT_PAGE::empty_lineEdit);
    connect(this, &MainWindow::empty_lineEdit,
            ui->account_card_borrow_page, &ACCOUNT_CARD_BORROW_PAGE::empty_lineEdit);
    connect(ui->search_page, &SEARCH_PAGE::searchByMultiCodt,
            this, &MainWindow::searchByMultiCodt);
    connect(this, &MainWindow::searchResult_mult,
            ui->search_page, &SEARCH_PAGE::searchResult_mult);
    createDir();
}


void MainWindow::readStu_ID_info(Account_info account_info){
    qsQuery.prepare("select * from stu_info where stu_ID = :stu_ID_");
    qsQuery.bindValue(":stu_ID_", account_info.stu_ID);
//    qDebug() << "account_info.stu_ID: " << account_info.stu_ID;
    if (!qsQuery.exec()){
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
        return;
    }
    if(qsQuery.first()){ // result is not empty
        account_info.stu_name = qsQuery.value("stu_name").toString();
        account_info.stu_college = qsQuery.value("stu_college").toString();
        account_info.stu_class = qsQuery.value("stu_class").toString();
        account_info.stu_sex = qsQuery.value("stu_sex").toString();
        account_info.stu_indentification_number = qsQuery.value("stu_indentification_number").toString();
        account_info.stu_status_of_student_status = qsQuery.value("stu_status_of_student_status").toString();
        account_info.account_in_time = qsQuery.value("account_in_time").toString();
        account_info.account_out_time = qsQuery.value("account_out_time").toString();
        account_info.borrow_time = qsQuery.value("borrow_time").toString();
        account_info.return_time = qsQuery.value("return_time").toString();
        account_info.photoPath = qsQuery.value("photoPath").toString();
        emit searchResult(account_info);
    }
    else {
        QMessageBox::warning(this, "警告", "查无此人");
    }
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

void MainWindow::createMySQL_Table(){
    qsQuery.prepare("CREATE TABLE IF NOT EXISTS stu_info("
                    "stu_name varchar(20) not null, "
                    "stu_ID int primary key, "
                    "stu_college varchar(20) not null, "
                    "stu_class varchar(20) not null, "
                    "stu_sex varchar(1) not null, "
                    "stu_indentification_number varchar(18) not null, "
                    "stu_status_of_student_status varchar(20) not null,"
                    "account_in_time  varchar(20) not null, "
                    "account_out_time varchar(20),"
                    "borrow_time varchar(20),"
                    "return_time varchar(20),"
                    "photoPath varchar(50))");
    if (qsQuery.exec()){
//        QMessageBox::information(this, "通知", "stu_info Table 创建成功");
    }
    else {
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
    }
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
    qsQuery.prepare("INSERT INTO stu_info(stu_name, stu_ID, stu_college,"
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
    qsQuery.prepare("select * from stu_info where stu_ID = :stu_ID_");
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
            account_info.stu_sex = qsQuery.value("stu_sex").toString();
            account_info.stu_indentification_number = qsQuery.value("stu_indentification_number").toString();
            account_info.stu_status_of_student_status = qsQuery.value("stu_status_of_student_status").toString();
            account_info.account_in_time = qsQuery.value("account_in_time").toString();
            account_info.account_out_time = qsQuery.value("account_out_time").toString();
            account_info.borrow_time = qsQuery.value("borrow_time").toString();
            account_info.return_time = qsQuery.value("return_time").toString();
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

void MainWindow::searchByMultiCodt(Account_info account_info){
    QString stm = "SELECT * FROM stu_info WHERE ";
    bool first = true;
    if (account_info.stu_ID != 0){
        stm += "stu_ID = :stu_ID";
        qsQuery.prepare(stm);
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
                account_info.stu_sex = qsQuery.value("stu_sex").toString();
                account_info.stu_indentification_number = qsQuery.value("stu_indentification_number").toString();
                account_info.stu_status_of_student_status = qsQuery.value("stu_status_of_student_status").toString();
                account_info.account_in_time = qsQuery.value("account_in_time").toString();
                account_info.account_out_time = qsQuery.value("account_out_time").toString();
                account_info.borrow_time = qsQuery.value("borrow_time").toString();
                account_info.return_time = qsQuery.value("return_time").toString();
                account_info.photoPath = qsQuery.value("photoPath").toString();
                emit searchResult_mult(account_info);
            }
            else{
                QMessageBox::warning(this, "警告", "查无此人");
            }
         }

    }
    if (!account_info.stu_name.isEmpty()){
        first = false;
        stm += "stu_name = :stu_name_";
    }
}

void MainWindow::addOutAccountTime(Account_info account_info){
    qsQuery.prepare("update stu_info set account_out_time = :account_out_time_ where stu_ID = :stu_ID_");
    qsQuery.bindValue(":account_out_time_", account_info.account_out_time);
    qsQuery.bindValue(":stu_ID_", account_info.stu_ID);
//    qDebug() << account_info.stu_ID;
//    qDebug() << account_info.account_out_time;
    if (!qsQuery.exec()){
        QSqlError error(qsQuery.lastError());
        QMessageBox::warning(this, "警告", error.text());
        return;
    }
    else {
        QMessageBox::information(this, "通知", "添加成功");
    }
}

void MainWindow::addTime(Account_info account_info){
    qsQuery.prepare("update stu_info set borrow_time = :borrow_time,"
                    "return_time = :return_time where stu_ID = :stu_ID_");
    qsQuery.bindValue(":borrow_time", account_info.borrow_time);
    qsQuery.bindValue(":return_time", account_info.return_time);
    qsQuery.bindValue(":stu_ID_", account_info.stu_ID);
//    qDebug() << account_info.stu_ID;
//    qDebug() << account_info.account_out_time;
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
    emit empty_lineEdit();
}

void MainWindow::on_account_card_borrow_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage2);
    emit empty_lineEdit();
}

void MainWindow::on_search_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stackedWidgetPage3);
    emit empty_lineEdit();
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
