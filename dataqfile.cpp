#include"dataqfile.h"
#include<QApplication>
#include<QIODevice>
#include<QFileInfo>
#include<QDir>
#include<QIODevice>
#include<QWidget>
#include<iostream>


SDataQfile::SDataQfile():

     data ("data.txt"),
     sign ("sign.dat"),
     change ("change.dat"),
     initdatas(& data),
     getdata_lastlines(&sign),
     getdata_thislines(&change)
{


}


qint32 SDataQfile::initdata(){/*
                               *we Regulations the txt as
                               * data just one line one data
                               *
                               * read and assignment that data one by on
                               */
    QString str;
    qint32 number;



    //QTextStream initdata(& data);
    initdatas >> str;
    //if(str.isNull())return -1;

    number = str.toInt();//number get data with qint32

    return number;

}


qint32 SDataQfile:: getdata_lastline(){

    qint32 number = -1;
    //QDataStream getdata_lastline(&sign);

    getdata_lastlines >> number;
    return number;
}//return a data from sign

qint32 SDataQfile::getdata_thisline(){

    qint32 number = -1;
   // QDataStream getdata_thisline(&change);

    getdata_thislines >>number;

    return number;
}//return a data from changeclose_getla


void SDataQfile::ass_lastline(qint32 data){

    //QDataStream getdata_lastline(&sign);
    getdata_lastlines <<data;

}

void SDataQfile::ass_thisline(qint32 data){

    //QDataStream getdata_thisline(&sign);
    getdata_thislines <<data;
    //getdata_thislines.device()->seek(1);

}

void SDataQfile::assignmentdata(qint32 i){

    qint32 number;
 // QString str;

   // QDataStream getdata_lastline(&sign);  //lastline
    //QDataStream getdata_thisline(&change);//thisline

    //change line :
    while(--i){
        getdata_thislines >> number;
        //std::cout<<".";
        getdata_lastlines << number;
    }
    getdata_lastlines.device()->seek(0);
}




void SDataQfile::close_init(){

    data.close();

}


void SDataQfile::close_getth(){

    change.close();
    change.open(QIODevice::WriteOnly);
    change.close();
}

void SDataQfile::close_getla(){

    sign.close();
    sign.open(QIODevice::WriteOnly);
    sign.close();
}


void SDataQfile::open_getla(){

    sign.open(QIODevice::ReadWrite);

}


void SDataQfile::open_init(){

    data.open(QIODevice::ReadWrite);    
}


void SDataQfile::open_getth(){

    change.open(QIODevice::ReadWrite);

}

void SDataQfile::setstartth(){

    getdata_thislines.device()->seek(0);
}

bool SDataQfile::is_end(){

    QTextStream data_s(&data);
    if(data_s.atEnd())
        return true;
    else
        return false;
}
