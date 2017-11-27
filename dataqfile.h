
#ifndef DATAQFILE_H
#define DATAQFILE_H
#include <QFile>
#include <QDebug>
#include <QDataStream>
#include <QTextStream>

class SDataQfile : public QFile{

    Q_OBJECT
private:
    QFile data;
    QFile sign;
    QFile change;
    QTextStream initdatas;
    QDataStream getdata_lastlines;
    QDataStream getdata_thislines;

public:
    SDataQfile();

public:

    qint32 getdata_lastline(); //last line
    qint32 initdata();      //get one data and return it

    qint32 getdata_thisline();//this line and give this data to sign.dat

    void assignmentdata(qint32);  //this func is use to assignment
                            //thisline and last line's data

    void ass_lastline(qint32);//get in a data
    void ass_thisline(qint32);//get in a data

    void close_getla();
    void close_init();
    void close_getth();

    void open_getla();
    void open_init();
    void open_getth();

    void setstartth();

    bool is_end();
};
#endif // DATAQFILE_H
