//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "puppyTestApp.h"
#include "puppyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<puppyTestApp>()
{
  InputParameters params = validParams<puppyApp>();
  return params;
}

puppyTestApp::puppyTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  puppyApp::registerObjectDepends(_factory);
  puppyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  puppyApp::associateSyntaxDepends(_syntax, _action_factory);
  puppyApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  puppyApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    puppyTestApp::registerObjects(_factory);
    puppyTestApp::associateSyntax(_syntax, _action_factory);
    puppyTestApp::registerExecFlags(_factory);
  }
}

puppyTestApp::~puppyTestApp() {}

void
puppyTestApp::registerApps()
{
  registerApp(puppyApp);
  registerApp(puppyTestApp);
}

void
puppyTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
puppyTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
puppyTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
puppyTestApp__registerApps()
{
  puppyTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
puppyTestApp__registerObjects(Factory & factory)
{
  puppyTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
puppyTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  puppyTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
puppyTestApp__registerExecFlags(Factory & factory)
{
  puppyTestApp::registerExecFlags(factory);
}
