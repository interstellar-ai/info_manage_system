#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QFrame>
#include <QMessageBox>

namespace Ui {
class Login_page;
}

class Login_page : public QFrame
{
    Q_OBJECT

public:
    explicit Login_page(QWidget *parent = nullptr);
    ~Login_page();

signals:
    void login_usr_passwd(QString usr, QString passwd);

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    void set_button();

private:
    Ui::Login_page *ui;
};

#endif // LOGIN_PAGE_H
