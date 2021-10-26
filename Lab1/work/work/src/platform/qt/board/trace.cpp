#include <config/trace-config.h>

#if (USE_PLATFORM_QT_TRACE != 0)

#include <QDebug>
#include <QTime>
#include "trace/trace.h"

#define ADD_CRLF_SEQU 	0

//static
void Trace::initialize()
{

}

void Trace::out(string str)
{
//    qDebug(str.data());
    static QTime old = QTime::currentTime();
    QTime now = QTime::currentTime();
    int dif = abs(now.msec()-old.msec());

    old=now;

    printf("%s,%s\t,%d\r\n",QTime::currentTime().toString("hh:mm:ss.zzz").toStdString().c_str(),str.data(),dif);
}

void Trace::out(const char * format, ...)
{
    char str[255];

    va_list args;

    va_start(args, format);
    vsprintf(str, format, args);
    va_end(args);

    qDebug(str);
}

#endif // USE_PLATFORM_QT_TRACE
