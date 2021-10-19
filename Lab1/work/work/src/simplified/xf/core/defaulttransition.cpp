#include "xf/defaulttransition.h"

// TODO: Implement code for XFDefaultTransition class  
XFDefaultTransition::XFDefaultTransition(interface::XFBehavior *pBehavior):XFEvent(DefaultTransition)
{

}

bool XFDefaultTransition::deleteAfterConsume() const
{
	return true;
}
