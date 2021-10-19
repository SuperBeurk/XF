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
    //call dispatcher method to add event to event list
    interface::XFDispatcher::getInstance()->pushEvent(pEvent,fromISR);
}

bool XFBehavior::deleteOnTerminate() const
{
    return deleteOnTerminate_;
}

void XFBehavior::setDeleteOnTerminate(bool deleteBehaviour)
{
     deleteOnTerminate_=deleteBehaviour;
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
    XFEventStatus status =processEvent();
    if((pEvent->deleteAfterConsume()==true) && ((status==XFEventStatus::Consumed)||(status==XFEventStatus::Terminate))){
    	delete pEvent;//delete event after consumed or if terminated
    }
    return ((deleteOnTerminate_)&&(status==XFEventStatus::Terminate));//return true if we have deleteOnTerminate attribute set and if status is an Terminate Event
}
