#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <QWidget>
#include <QBitmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("彩票分析系统");
   // QPainter painter(this);
    QPixmap pixmap("/home/swb/下载/91807f89d8fd1b9f91e4d22cf1f3f594.jpg");
    ui->textBrowser->setWordWrapMode(QTextOption::NoWrap);
    ui->textBrowser->moveCursor(QTextCursor::End);
    //ui->textBrowser->document()->lineCount();
    //ui->textBrowser->document()->setMaximumBlockCount(100000);
    //ui->textBrowser->lineWrapMode();
    //ui->textEdit->lineWrapMode();
    //ui->textBrowser->setText("");
    ui->textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //ui->textEdit->setText("");
    QFile datas("data.txt");
    datas.open(QIODevice::ReadOnly);
    QTextStream dataread(&datas);
    ui->textEdit->setText(dataread.readAll());
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::pushthat_on_ui);
        //s = new QScrollArea(this);
        //setCentralWidget(s);
        //s->setGeometry(0,0,400,400);
        //垂直滚动条不可见，只能通过鼠标滑动
        //s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //w = new QWidget(s);
        //ws = new QWidget(this);
        //setMenuWidget(w);
        //setMenuWidget(ws);
        //s->setWidget(w);
        //w->setGeometry(0,0,1000,1000);

        //label = new QLabel(w);

      // textEdit= new QTextEdit(w);
      // textBrowser = new QTextBrowser(w);
       //textBrowser_1 = new QTextBrowser(w);

       //textBrowser->setText("sssss\n");
       //textBrowser->setGeometry(0,0,1000,1000);
       //textBrowser->setText("ssssssssssss\n");
       // btn = new QPushButton(w);
       // setCentralWidget(textBrowser);
       // btn->setText("1223");
        //btn->move(230,130);


}


void MainWindow::pushthat_on_ui(){

    QFile push_ui("push.txt");
    QTextStream push(&push_ui);
    push_ui.open(QIODevice::ReadOnly);

    ui->textBrowser->setText(push.readAll());

    push_ui.close();
    push_ui.open(QIODevice::WriteOnly);
    push_ui.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
