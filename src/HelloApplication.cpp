#include "HelloApplication.h"
using namespace Wt;

//______________________________________________________________________________
HelloApplication::HelloApplication(const WEnvironment& env)
: WApplication(env)
{
	// Application Title
	setTitle("Hello world");

	// Show some text
	root()->addWidget(new WText("Your name, please ? "));

	// Add an editable text box and put the cursor in it
	m_nameEdit = new WLineEdit(root());
	m_nameEdit->setFocus();


	// Create a push-button with a 5 pixel margin
	WPushButton *b1 = new WPushButton("Greet me.", root());

	// Insert a line break
	root()->addWidget(new WBreak());

	// Make an area for text
	m_greeting = new WText(root());

	/*
	 * Connect signals with slots
	 *
	 * - simple Wt-way
	 */
	b1->clicked().connect(this, &HelloApplication::greet);

	/*
	 * - using an arbitrary function object (binding values with boost::bind())
	 */
	m_nameEdit->enterPressed().connect
			(boost::bind(&HelloApplication::greet, this));

	// Add line break
	root()->addWidget(new WBreak());

	// Add a exit button
	WPushButton *b2 = new WPushButton("Exit", root());
	b2->clicked().connect(this, &HelloApplication::exit);

}


//______________________________________________________________________________
void HelloApplication::greet()
{
	/*
	 * Update the text, using text input into the nameEdit_ field.
	 */
	m_greeting->setText("Hello there, " + m_nameEdit->text());
}


//______________________________________________________________________________
void HelloApplication::exit()
{
	root()->clear();
	WApplication::quit();
	std::exit(EXIT_SUCCESS);
}
