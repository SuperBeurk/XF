#include <config/xf-config.h>

#if (USE_XF_IDF_STM32_EVENT_QUEUE_CLASS != 0)

#include <cassert>
#include "eventqueue.h"

// TODO: Implement code for XFEventQueue class

#endif // USE_XF_IDF_STM32_EVENT_QUEUE_CLASS

XFEventQueue::XFEventQueue() {
}

XFEventQueue::~XFEventQueue() {
}

bool XFEventQueue::empty() const {
	return _queue.empty();
}

bool XFEventQueue::push(const XFEvent *pEvent, bool fromISR) {
	if(fromISR)
	{
		_mutex.lock();
	}
	_queue.push(pEvent);
	if(fromISR)
	{
		_mutex.unlock();
	}
	return true;
}

const XFEvent* XFEventQueue::front() {
	return _queue.front();
}

void XFEventQueue::pop() {
	_queue.pop();
}

bool XFEventQueue::pend() {
	return !(_queue.empty());
}
