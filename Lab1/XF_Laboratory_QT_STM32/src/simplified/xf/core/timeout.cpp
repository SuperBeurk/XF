#include "xf/timeout.h"

// TODO: Implement code for XFTimeout class

XFTimeout::XFTimeout(int id, int interval, interface::XFBehavior *pBehavior):XFEvent(Timeout,id,pBehavior)
{
    id_=id;
    interval_=interval;
    pBehavior_=pBehavior;
    relTicks_=interval;
}

bool XFTimeout::operator ==(const XFTimeout &timeout) const
{
	return false;
}

bool XFTimeout::deleteAfterConsume() const
{
	return true;
}
