#include "xf/xf.h"
#include "trace/trace.h"
#include "testfactory05.h"

void Factory_initialize()
{
    TestFactory05::initialize();
}

void Factory_build()
{
    TestFactory05::build();
}

StateMachine05a TestFactory05::task01_("Tick 500ms");
StateMachine05b TestFactory05::task02_(" One");
StateMachine05b TestFactory05::task03_("  Two");
StateMachine05b TestFactory05::task04_("   Three");

TestFactory05::TestFactory05()
{
}

// static
void TestFactory05::initialize()
{
}

// static
void TestFactory05::build()
{
	Trace::out("Starting test5...");
	Trace::out("---------------------");
	// Start state machine(s)
	task01_.startBehavior();
	task02_.startBehavior();
	task03_.startBehavior();
	task04_.startBehavior();
}
