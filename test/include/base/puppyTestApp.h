//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef PUPPYTESTAPP_H
#define PUPPYTESTAPP_H

#include "MooseApp.h"

class puppyTestApp;

template <>
InputParameters validParams<puppyTestApp>();

class puppyTestApp : public MooseApp
{
public:
  puppyTestApp(InputParameters parameters);
  virtual ~puppyTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* PUPPYTESTAPP_H */
