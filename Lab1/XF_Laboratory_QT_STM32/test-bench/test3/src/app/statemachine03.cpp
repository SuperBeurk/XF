#include <stdio.h>
#include "trace/trace.h"
#include "events/evrestart.h"
#include "statemachine03.h"

StateMachine03::StateMachine03()
{
	currentState_ = STATE_INITIAL;
}

StateMachine03::~StateMachine03()
{

}

/**
 * Implements state machine behavior.
 */
XFEventStatus StateMachine03::processEvent()
{
	eEventStatus eventStatus = XFEventStatus::Unknown;

	switch (currentState_)
	{
	case STATE_INITIAL:
		{
			if (getCurrentEvent()->getEventType() == XFEvent::Initial)
			{
				GEN(XFDefaultTransition());

				currentState_ = STATE_WAIT;
				eventStatus = XFEventStatus::Consumed;
			}
		}
		break;
	case STATE_WAIT:
		{
			if (getCurrentEvent()->getEventType() == XFEvent::DefaultTransition ||
				(getCurrentEvent()->getEventType() == XFEvent::Event &&
				 getCurrentEvent()->getId() == EventId::evRestart))
			{
				{
					Trace::out("Wait");
				}

                scheduleTimeout(Timeout_WAIT_id, 2000);

				currentState_ = STATE_SEND_RESTART;
				eventStatus = XFEventStatus::Consumed;
			}
		}
		break;
	case STATE_SEND_RESTART:
		{
			if (getCurrentEvent()->getEventType() == XFEvent::Timeout &&
				getCurrentTimeout()->getId() == Timeout_WAIT_id)
			{
				{
					Trace::out("Wait restart");
					GEN(evRestart());
				}

				currentState_ = STATE_WAIT;
				eventStatus = XFEventStatus::Consumed;
			}
		}
		break;
	default:
		break;
	}

	return eventStatus;
}
