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
    QTime now = QTime::currentTime();
    string out=now.toString("hh:mm:ss.zzz").toStdString()+" "+str;
    qDebug()<<out.data();
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
