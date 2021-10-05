#include <stdio.h>
#include "trace/trace.h"
#include "statemachine05a.h"

/**
 * Constructor
 *
 * \param text Text to display by the state machine.
 */
StateMachine05a::StateMachine05a(string text)
 : text_(text)
{
	currentState_ = STATE_INITIAL;
}

StateMachine05a::~StateMachine05a()
{

}

XFEventStatus StateMachine05a::processEvent()
{
	eEventStatus eventStatus = XFEventStatus::Unknown;

	switch (currentState_)
	{
	case STATE_INITIAL:
		{
			if (getCurrentEvent()->getEventType() == XFEvent::Initial)
			{
				GEN(XFDefaultTransition());

				currentState_ = STATE_SAY_TEXT;

				eventStatus = XFEventStatus::Consumed;
			}
		}
		break;
	case STATE_SAY_TEXT:
		{
			if (getCurrentEvent()->getEventType() == XFEvent::DefaultTransition ||
				(getCurrentEvent()->getEventType() == XFEvent::Timeout &&
				 getCurrentTimeout()->getId() == Timeout_SAY_HELLO_id))
			{
				{
					Trace::out(getText());
				}

                scheduleTimeout(Timeout_SAY_HELLO_id, 500);

				currentState_ = STATE_SAY_TEXT;

				eventStatus = XFEventStatus::Consumed;
			}
		}
		break;
	default:
		break;
	}

	return eventStatus;
}
