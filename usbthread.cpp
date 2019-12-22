#include "usbthread.h"

USBThread::USBThread()
{
    is_loop = true;
}

void USBThread::run()
{
    is_loop = true;
    while(is_loop)
    {
        //DBG("thread");
        libusb_handle_events(NULL);
        msleep(1);
    }
    DBG("usb thread exit");
}

void USBThread::close()
{
    is_loop = false;
}
