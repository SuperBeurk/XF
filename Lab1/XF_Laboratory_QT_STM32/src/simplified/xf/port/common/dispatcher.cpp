#include <cassert>
#include <config/xf-config.h>

#if (USE_XF_COMMON_DISPATCHER_CLASS != 0)
#if (XF_TRACE_EVENT_PUSH_POP != 0)
    #include "trace/trace.h"
#endif // XF_TRACE_EVENT_PUSH_POP
#include "xf/eventstatus.h"
#include "xf/interface/timeoutmanager.h"
#include "xf/interface/behavior.h"
#include "xf/interface/mutex.h"
#include "dispatcher.h"

using interface::XFTimeoutManager;      // Allows to use expression 'XFTimeoutManager' instead of 'interface::XFTimeoutManager'.
using interface::XFBehavior;            // Expression XFBehavior used in code below is in fact the XFBehavior interface class.
using Mutex = interface::XFMutex;       // Rename XFMutex interface class to Mutex for easier use.

interface::XFDispatcher * interface::XFDispatcher::getInstance()
{
    static ::XFDispatcher dispatcher;
    return &dispatcher;
}

// TODO: Implement code for XFDispatcher class  

XFDispatcher::XFDispatcher()
{

}

XFDispatcher::~XFDispatcher()
{

}

void XFDispatcher::pushEvent(XFEvent *pEvent, bool fromISR)
{
    _events.push(pEvent,fromISR);//Push an XF event to our event list
}

void XFDispatcher::scheduleTimeout(int timeoutId, int interval, interface::XFBehavior *pBehavior)
{
    //call timeout manager schedule timeout
    interface::XFTimeoutManager::getInstance()->scheduleTimeout(timeoutId,interval,pBehavior);//Call scheduleTimeout method from XF::TimeoutManager

}

void XFDispatcher::unscheduleTimeout(int timeoutId, interface::XFBehavior *pBehavior)
{
    //call timeout manager schedule timeout
    interface::XFTimeoutManager::getInstance()->unscheduleTimeout(timeoutId,pBehavior);//Call unscheduleTimeout method from XF::TimeoutManager
}

void XFDispatcher::executeOnce()
{
    if(_events.empty()==0)
    {
        dispatchEvent(_events.front());//dispatch first event of the list
        _events.pop();//Pop it of the list
    }
    else {
        _events.pend();
    }
}

int XFDispatcher::execute(const void *param)
{
    while(1)
    {
        executeOnce();
    }
}

void XFDispatcher::dispatchEvent(const XFEvent *pEvent) const
{
    //Dispatch event that has been pop
    XFBehavior::TerminateBehavior pTerminate=pEvent->getBehavior()->process(pEvent);//Distribute the event that has been pop to the correct stateMachine
    if(pTerminate)
    {
        delete pEvent->getBehavior();//Kill the stateMachine if it's in terminate event
    }

}

#endif // USE_XF_COMMON_DISPATCHER_CLASS

