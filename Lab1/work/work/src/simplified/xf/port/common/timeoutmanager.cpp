
#include <config/xf-config.h>

#if (USE_XF_COMMON_TIMEOUTMANAGER_CLASS != 0)

#include <cassert>
#include "xf/interface/behavior.h"
#include "xf/interface/mutex.h"
#include "timeoutmanager.h"

using Mutex = interface::XFMutex;       // Rename XFMutex interface class to Mutex for easier use.

interface::XFTimeoutManager * interface::XFTimeoutManager::getInstance()
{
    static ::XFTimeoutManager timeoutManager;
    return &timeoutManager;
}
// TODO: Implement code for XFTimeoutManager class  
XFTimeoutManager::XFTimeoutManager()
{

}
XFTimeoutManager::~XFTimeoutManager()
{

}
void XFTimeoutManager::start(std::function<void (uint32_t)> startTimeoutManagerTimer)
{
    startTimeoutManagerTimer(tickInterval_);
}
void XFTimeoutManager::scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior *pBehavior)
{
     timeouts_.push_back(new XFTimeout(timeoutId,interval,pBehavior));

}
void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{
    /*for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();it++)
    {
        if(((*it)->getId()==timeoutId)&&(((*it)->getBehavior())==pBehavior))
        {
            timeouts_.erase(it);
            break;
        }
    }
    for(XFTimeout* timeout : timeouts_)
    {

    }*/
}
void XFTimeoutManager::tick()
{

    for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();it++)
    {
        if((*it)->getRelTicks()==0)
        {
            //Create new event because timer is finished
            (*it)->getBehavior()->pushEvent((*it),true);
            timeouts_.erase(it);
            break;
        }
        else
        {
            (*it)->substractFromRelTicks(tickInterval_);
        }

    }
}
void XFTimeoutManager::addTimeout(XFTimeout *pNewTimeout)
{
    //timeouts_.push_back(pNewTimeout);
}
void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{
    //get from list
}
#endif // USE_XF_COMMON_TIMEOUTMANAGER_CLASS
