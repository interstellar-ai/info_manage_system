#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <QString>
#include <QDate>

struct Account_info{
    QString stu_name;
    int stu_ID;
    QString stu_college;
    QString stu_class;
    QString stu_sex;
    QString stu_indentification_number;
    QString stu_status_of_student_status;
    QString account_in_time;
    QString account_out_time;
    QString photoPath;
};

struct Card_info{
    QString card_ID;
    int stu_ID;
};

struct BorrowCard{
    int stu_ID;
    QString reason;
    QString borrowDate;
    QString backDate;
    QString photoPath;
};

//extern QString borrowTableName = "borrowRecord";
//extern QString stuInfoTableName = "stu_info";

#endif // DATA_STRUCT_H
