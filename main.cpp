#include "mainwindow.h"



#include"dataqfile.h"
#include<QApplication>
#include<QIODevice>
#include<QFileInfo>
#include<QDir>
#include<QIODevice>
#include<QWidget>
#include<iostream>
#include<string>

void Test(){

    QFile pushdata("push.txt");
    QTextStream getin(&pushdata);
    pushdata.open(QIODevice::ReadWrite);
    QString str;
    qint32 data;
    SDataQfile Datafile;
    qint32 check = 0;
    qint32 plus_data;
    qint32 i = 0;
    qint32 j = 0;
    qint32 cache;
    qint32 ass;
    //QStringList strlist;
    Datafile.open_init();//open DATA file

    while(1){
        i++;
        //data = Datafile.initdata();// get DATADatafile.ass_lastline(data);
        Datafile.open_getla();
        data = Datafile.initdata();// get DATADatafile.ass_lastline(data);
        //Datafile.ass_lastline(data);
        if(data == -1)break;
        std::cout<<Datafile.is_end();
        //if(data == -1)break;

            if(check==1){

                Datafile.assignmentdata(i);// thisline to lastline
                Datafile.close_getth();
            }
            //std::cout<<data<<" ";
            str = QString::number(data,10);
            getin << str;
            str = (QString)" ";
            getin << str;
           // strlist.append((QString)data);
            Datafile.open_getth();//open;
            Datafile.ass_thisline(data);
            cache = data;
            j = i;

            while(--j){//one line

                plus_data = Datafile.getdata_lastline(); //plus data
               //std::cout<<"*"<<plus_data<<"* ";
                ass = (plus_data+cache)%10;
                //std::cout<<ass<<" ";
                str = QString::number(ass,10);
                getin <<str;
                str = (QString)" ";
                getin <<str;

                    Datafile.ass_thisline(ass);

                    cache = ass;
                    check = 1;

            }
            check = 1;
            //std::cout<<std::endl;
            str = (QString)"\n";
            getin<<str;
            Datafile.close_getla();//closed
            Datafile.setstartth();

    }
    //getin.device()->seek(0);
    pushdata.close();
    Datafile.close_init();

}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    Test();

    return a.exec();
}
