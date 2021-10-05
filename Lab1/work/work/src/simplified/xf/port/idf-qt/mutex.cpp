#include <config/xf-config.h>

#if (USE_XF_IDF_QT_MUTEX_CLASS != 0)

#include <cassert>
#include "mutex.h"

/**
 * @brief Implementation of interface::XFMutex::create method.
 */
interface::XFMutex * interface::XFMutex::create()
{
    return new ::XFMutex;
}

// TODO: Implement code for XFMutex class 
void XFMutex::lock()
{

}
void XFMutex::unlock()
{

}

bool XFMutex::tryLock(int32_t timeout)
{

}

#endif // USE_XF_IDF_QT_MUTEX_CLASS

