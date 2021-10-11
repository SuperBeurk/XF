
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
             if((*it)->getRelTicks()>interval)//Insert in middle of the list
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
         timeouts_.push_back(new XFTimeout(timeoutId,interval,pBehavior));
         timeouts_.back()->setRelTicks(timeouts_.back()->getRelTicks()-sub);

     }

}
void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{

}
void XFTimeoutManager::tick()
{
    if(timeouts_.empty()==false)
    {
        for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();)
        {
            if((*it)->getRelTicks()<=0)
            {
                (*it)->getBehavior()->pushEvent((*it),true);
                it=timeouts_.erase(it);
            }
            else
            {
                it++;
            }
        }
        timeouts_.front()->substractFromRelTicks(tickInterval_);
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
