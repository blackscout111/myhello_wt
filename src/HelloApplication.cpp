#include "HelloApplication.h"
using namespace Wt;

//______________________________________________________________________________
HelloApplication::HelloApplication(const WEnvironment& env)
  : WApplication(env)
{
  setTitle("Hello world");                               // application title

  root()->addWidget(new WText("Your name, please ? "));  // show some text
  nameEdit_ = new WLineEdit(root());                     // allow text input
  nameEdit_->setFocus();                                 // give focus

  WPushButton *b1 = new WPushButton("Greet me.", root());// create a button
  b1->setMargin(5, Left);                                 // add 5 pixels margin

  root()->addWidget(new WBreak());                       // insert a line break

  greeting_ = new WText(root());                         // empty text

  /*
   * Connect signals with slots
   *
   * - simple Wt-way
   */
  b1->clicked().connect(this, &HelloApplication::greet);

  /*
   * - using an arbitrary function object (binding values with boost::bind())
   */
  nameEdit_->enterPressed().connect(this, &HelloApplication::greet);

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
  greeting_->setText("Hello there, " + nameEdit_->text());
}


//______________________________________________________________________________
void HelloApplication::exit()
{
	root()->clear();
	WApplication::quit();
}
