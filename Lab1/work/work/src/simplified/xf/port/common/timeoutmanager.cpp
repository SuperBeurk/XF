
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
    startTimeoutManagerTimer(tickInterval_);//Start timer wich will tick every tickInterval ms
}
void XFTimeoutManager::scheduleTimeout(int32_t timeoutId, int32_t interval, interface::XFBehavior *pBehavior)
{
     XFTimeout* pNewTimeOut = new XFTimeout(timeoutId,interval,pBehavior);//Create new XFTimeout with parameters
     addTimeout(pNewTimeOut);//Add it to the list
}
void XFTimeoutManager::unscheduleTimeout(int32_t timeoutId, interface::XFBehavior *pBehavior)
{
    for(std::list<XFTimeout *>::iterator it=timeouts_.begin();it!=timeouts_.end();it++)//Parcour the list
    {
        if((*it)->getId()==timeoutId)//Check current timer id with id to delete
        {
            it=timeouts_.erase(it);//delete element and update iterator
        }
    }
}
void XFTimeoutManager::tick()
{
    if(timeouts_.empty()==false)
    {
        timeouts_.front()->substractFromRelTicks(tickInterval_);//Substract front timer with tickInterval
        if(timeouts_.front()->getRelTicks()<=0)//If we reached the cooldown of the first timer
        {
            returnTimeout(timeouts_.front());//Push event of this timer
            timeouts_.pop_front();//Pop this timer of the timeouts list
        }
    }

}
void XFTimeoutManager::addTimeout(XFTimeout *pNewTimeout)
{
    std::list<XFTimeout *>::iterator it;
    bool insert = false;
    if(timeouts_.empty())
    {
        timeouts_.push_front(pNewTimeout);//Add first element
    }
    else //If we have at lest one element in the list
    {
        for(it=timeouts_.begin();it!=timeouts_.end();it++)//Parcour the list
        {
            if((*it)->getRelTicks()>(pNewTimeout->getRelTicks()))//Insert in middle of the list
            {
                (*it)->substractFromRelTicks(pNewTimeout->getRelTicks());//Modify the following timer reltick
                insert=true;//Insert to true
                break;//leave for boucle

            }
            else
            {
                pNewTimeout->substractFromRelTicks((*it)->getRelTicks());//Substract our New timer relTicks
            }
        }
        if(insert)
        {
            timeouts_.insert(it,pNewTimeout);//Insert new timer at it position
        }
        else {
            timeouts_.push_back(pNewTimeout);//Insert new timer at end of list
        }
    }
}
void XFTimeoutManager::returnTimeout(XFTimeout *pTimeout)
{
    pTimeout->getBehavior()->pushEvent(pTimeout,false);//Push event from the timer that is timeout
}
#endif // USE_XF_COMMON_TIMEOUTMANAGER_CLASS
