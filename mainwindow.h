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
    
private:
    Ui::MainWindow *ui;
    
private slots:
    void usbRecvSlot(unsigned char *buf,int len);
    void disconnectSlot(void);
    void on_pb_open_clicked();
    void on_pb_send_clicked();
};

#endif // MAINWINDOW_H
