#include "puppyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<puppyApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

puppyApp::puppyApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  puppyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  puppyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  puppyApp::registerExecFlags(_factory);
}

puppyApp::~puppyApp() {}

void
puppyApp::registerApps()
{
  registerApp(puppyApp);
}

void
puppyApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"puppyApp"});
}

void
puppyApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"puppyApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
puppyApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
puppyApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
puppyApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
puppyApp__registerApps()
{
  puppyApp::registerApps();
}

extern "C" void
puppyApp__registerObjects(Factory & factory)
{
  puppyApp::registerObjects(factory);
}

extern "C" void
puppyApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  puppyApp::associateSyntax(syntax, action_factory);
}

extern "C" void
puppyApp__registerExecFlags(Factory & factory)
{
  puppyApp::registerExecFlags(factory);
}
