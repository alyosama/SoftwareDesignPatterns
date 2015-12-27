#include "Context.h"

Context::Context(void)
{
}

Context::~Context(void)
{
}

bool Context::Lookup(const char* paramName) const
{
    if (strcmp(xName, paramName) == 0)
        return xValue;

    if (strcmp(yName, paramName) == 0)
        return yValue;

    return false;
}

void Context::AssignX(VariableExpression* anExpression, bool xBoolValue)
{
    xValue = xBoolValue;
    xName = anExpression->getName();
}

void Context::AssignY(VariableExpression* anExpression, bool yBoolValue)
{
    yValue = yBoolValue;
    yName = anExpression->getName();
}
