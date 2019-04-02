#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_in_out_account_clicked();

    void on_account_card_borrow_clicked();

    void on_search_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
