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
    connect_database();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    connect(ui->log_in_page, &Login_page::login_succsessfully,
            this, &MainWindow::restoreToolButton);
}

void MainWindow::connect_database(){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    if (!ok){
        QMessageBox::information(this, "infor", "connect failed");
        return;

    }
    qsQuery = QSqlQuery(db);
    QString strSqlText("SELECT * FROM user");//查询语法
    qsQuery.prepare(strSqlText);
    qsQuery.exec();
    qDebug() << qsQuery.result();
}

void MainWindow::restoreToolButton(){
    ui->in_out_account->setEnabled(true);
    ui->account_card_borrow->setEnabled(true);
    ui->search->setEnabled(true);
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
