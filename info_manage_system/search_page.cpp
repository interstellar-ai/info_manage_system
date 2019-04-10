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
