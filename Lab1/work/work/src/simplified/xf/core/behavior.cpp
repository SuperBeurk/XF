#include <cassert>
#include "xf/xf.h"
#include "xf/timeout.h"
#include "xf/initialevent.h"
#include "xf/behavior.h"

// TODO: Implement code for XFBehavior class 

XFBehavior::XFBehavior()
{

}

XFBehavior::~XFBehavior()
{

}

void XFBehavior::startBehavior()
{
    //Create default init event   
    GEN(XFInitialEvent);
}

void XFBehavior::pushEvent(XFEvent *pEvent, bool fromISR)
{
    pEvent->setBehavior(this);
    //Add event to event list
    interface::XFDispatcher::getInstance()->pushEvent(pEvent,fromISR);
}

bool XFBehavior::deleteOnTerminate() const
{

}

void XFBehavior::setDeleteOnTerminate(bool deleteBehaviour)
{

}

const XFEvent *XFBehavior::getCurrentEvent() const
{
    return pCurrentEvent_;
}

interface::XFDispatcher *XFBehavior::getDispatcher()
{
    return interface::XFDispatcher::getInstance();
}

const XFTimeout *XFBehavior::getCurrentTimeout()
{
    return (XFTimeout *)pCurrentEvent_;
}

void XFBehavior::setCurrentEvent(const XFEvent *pEvent)
{
    pCurrentEvent_=pEvent;
}

XFBehavior::TerminateBehavior XFBehavior::process(const XFEvent *pEvent)
{
    setCurrentEvent(pEvent);
    processEvent();
    //Delete pEvent
}
