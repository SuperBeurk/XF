
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
    //BAsic add
    // timeouts_.push_back(new XFTimeout(timeoutId,interval,pBehavior));

     //Smart add
     int sub=0;
     if(timeouts_.empty())
     {
         timeouts_.push_front(new XFTimeout(timeoutId,interval,pBehavior));//Add first element
     }
     else //If we have at lest one element in the list
     {
         for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();it++)//Parcour the list
         {
             if((*it)->getRelTicks()>interval||(*it)==timeouts_.back())
             {
                 it=timeouts_.insert(it,new XFTimeout(timeoutId,interval,pBehavior));//Add new Timeout
                 for(;it!=timeouts_.end();it++)//Set all tick after this element
                 {
                     (*it)->setRelTicks((*it)->getRelTicks()-sub);
                     sub+=(*it)->getRelTicks();
                 }
                 return;
             }
             else
             {
                 sub+=(*it)->getRelTicks();
             }
         }
     }

}
void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{

}
void XFTimeoutManager::tick()
{
    /*for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();it++)
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

    }*/
    if(timeouts_.empty()==0)
    {
        if(timeouts_.front()->getRelTicks()<=0)
        {
            timeouts_.front()->getBehavior()->pushEvent(timeouts_.front(),true);
            timeouts_.pop_front();
        }
        else
        {
            timeouts_.front()->substractFromRelTicks(tickInterval_);
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
