#ifndef SEARCH_PAGE_H
#define SEARCH_PAGE_H

#include <QFrame>

namespace Ui {
class SEARCH_PAGE;
}

class SEARCH_PAGE : public QFrame
{
    Q_OBJECT

public:
    explicit SEARCH_PAGE(QWidget *parent = nullptr);
    ~SEARCH_PAGE();
private:
    void set_pushuButton();

private:
    Ui::SEARCH_PAGE *ui;
};

#endif // SEARCH_PAGE_H
