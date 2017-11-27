#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
#include <QTextBrowser>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QScrollArea *s;
       QWidget *w;
       QPushButton *btn;
       QTextEdit *textEdit;
       QTextBrowser *textBrowser;
        QTextBrowser *textBrowser_1;
       QLabel *label;

       void pushthat_on_ui();
//       QWidget *ws;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
