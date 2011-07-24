#ifndef HelloApplication_h
#define HelloApplication_h

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>


using namespace Wt;
/*
 * A simple hello world application class which demonstrates how to react
 * to events, read input, and give feed-back.
 */
class HelloApplication : public WApplication
{
public:
	/*
	 * The env argument contains information about the new session, and
	 * the initial request. It must be passed to the WApplication
	 * constructor so it is typically also an argument for your custom
	 * application constructor.
	 */
	HelloApplication(const WEnvironment& env);

private:
	WLineEdit *m_nameEdit;
	WText *m_greeting;

	void greet();
	void exit();
};


#endif
