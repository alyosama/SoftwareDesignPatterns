#ifndef CONTEXT_H
#define CONTEXT_H

#include <string.h>
#include "VariableExpression.h"

class VariableExpression;

class Context
{
public:
    explicit Context(void);
    virtual ~Context(void);

    bool Lookup(const char*) const;
    void AssignX(VariableExpression*, bool);
    void AssignY(VariableExpression*, bool);

private:
    char* xName;
    char* yName;
    bool xValue;
    bool yValue;
};
#endif