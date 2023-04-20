#include "DolphinApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DolphinApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

DolphinApp::DolphinApp(InputParameters parameters) : MooseApp(parameters)
{
  DolphinApp::registerAll(_factory, _action_factory, _syntax);
}

DolphinApp::~DolphinApp() {}

void
DolphinApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"DolphinApp"});
  Registry::registerActionsTo(af, {"DolphinApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DolphinApp::registerApps()
{
  registerApp(DolphinApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DolphinApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DolphinApp::registerAll(f, af, s);
}
extern "C" void
DolphinApp__registerApps()
{
  DolphinApp::registerApps();
}
