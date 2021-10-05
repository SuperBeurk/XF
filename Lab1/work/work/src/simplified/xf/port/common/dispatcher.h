#ifndef XF_COMMON_DISPATCHER_H
#define XF_COMMON_DISPATCHER_H

#include <config/xf-config.h>

#if (USE_XF_COMMON_DISPATCHER_CLASS != 0)

#include "xf/interface/dispatcher.h"
#include "xf/interface/mutex.h"

/*
 * Please include the XFEventQueueDefault class in the xf-config file!
 * Example: #include "default/eventqueue-default.h"
 * and
 * define the XFEventQueueDefault class as the class representing the
 * XFEventQueue used by the dispatcher.
 * Example: using XFEventQueue = XFEventQueueDefault;
 *
 * In case you want to provide you own event queue, you must implement
 * your own XFEventQueue class and include the header file in the xf-config file.
 */

/** @ingroup port_common
 *  @{
 */

/**
 * @brief A dispatcher implementation which can be used without an OS.
 *
 * The dispatcher can be used when an IDF on a bare-metal embedded system is needed.
 */
class XFDispatcher : public interface::XFDispatcher
{
public:
    XFDispatcher();
    virtual  ~XFDispatcher();

    void pushEvent(XFEvent * pEvent, bool fromISR=false) override;

    void scheduleTimeout(int timeoutId, int interval, interface::XFBehavior * pBehavior) override;
    void unscheduleTimeout(int timeoutId, interface::XFBehavior * pBehavior) override;

    void executeOnce() override;
    int execute(const void * param = nullptr) override;

protected:
    void dispatchEvent(const XFEvent * pEvent) const override;

protected:
    XFEventQueue _events;               ///< Queue holding events waiting to get dispatched.
    interface::XFMutex * _pMutex;		///< Mutex to protect event queue.
};

/** @} */ // end of port_common group
#endif // USE_XF_COMMON_DISPATCHER_CLASS
#endif // XF_COMMON_DISPATCHER_H
