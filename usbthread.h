#ifndef USBTHREAD_H
#define USBTHREAD_H

#include <QThread>
#include "libusb.h"
#include "workspace.h"

class USBThread : public QThread
{
    Q_OBJECT
private:
    bool is_loop;
public:
    USBThread();
    void run();
    void close();
};

#endif // USBTHREAD_H
