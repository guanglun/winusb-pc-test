#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "winusbdriver.h"

WinUSBDriver winusb;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    this->setWindowTitle("WINUSB测试");
    
    connect(&winusb,SIGNAL(recvSignals(unsigned char *,int)),this,SLOT(usbRecvSlot(unsigned char *,int)));
    connect(&winusb,SIGNAL(disconnectSignals()),this,SLOT(disconnectSlot()));
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::usbRecvSlot(unsigned char *buf,int len)
{
    
    buf[len] = '\0';
    
    //DBG("recv:%s",buf);
    
    QString qstr = QString(QLatin1String((const char*)buf));
    ui->te_recv->append(qstr);
    ui->te_recv->moveCursor(QTextCursor::End);
}

void MainWindow::on_pb_open_clicked()
{
    if(ui->pb_open->text().compare(QString::fromUtf8("打开")) == 0)
    {
        int vid = ui->le_vid->text().toInt();
        int pid = ui->le_pid->text().toInt();
        if(winusb.open(vid,pid) == 0)
        {
            ui->pb_open->setText("关闭");
        }
    }else
    {
        winusb.close();
        ui->pb_open->setText("打开");
    }   
}
void MainWindow::disconnectSlot(void)
{
    winusb.close();
    ui->pb_open->setText("打开");
}

void MainWindow::on_pb_send_clicked()
{
    QByteArray bytes = ui->le_send->text().toUtf8();
    winusb.send(bytes);
}
