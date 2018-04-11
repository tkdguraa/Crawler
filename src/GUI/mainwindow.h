#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QThread>
#include"thread.h"
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void resizeEvent(QResizeEvent *event);
private slots:

void on_pushButton_2_clicked();
void on_search_clicked();

void on_topage1_1_clicked();

void on_topage2_1_clicked();

void on_topage3_1_clicked();

void on_topage1_2_clicked();

void on_topage2_2_clicked();

void on_topage3_2_clicked();

void on_topage1_3_clicked();

void on_topage2_3_clicked();

void on_topage3_3_clicked();

void on_search_2_clicked();

void on_search_3_clicked();

void on_pushButton_clicked();

public:
void makelabel(char *str, QVBoxLayout *vlayout, char **savesearch, int wordsnum);
void makelabel2(char *str, QVBoxLayout *vlayout,char **savesearch,int wordsnum);
void makelabel3(char *str, QVBoxLayout *vlayout,char **savesearch,int wordsnum);


private:
    Ui::MainWindow *ui;
public:
    class Thread:public QThread
    {
     //   Q_OBJECT
    public:
        void stop();
    public:
        void run();
    private:
        //volatile bool stopped;
    };
    Thread a;
};

#endif // MAINWINDOW_H
