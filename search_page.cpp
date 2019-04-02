#include "search_page.h"
#include "ui_search_page.h"

SEARCH_PAGE::SEARCH_PAGE(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SEARCH_PAGE)
{
    ui->setupUi(this);
}

SEARCH_PAGE::~SEARCH_PAGE()
{
    delete ui;
}
