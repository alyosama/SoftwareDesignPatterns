#ifndef VARIABLEEXPRESSION_H
#define VARIABLEEXPRESSION_H

#include "BooleanExpression.h"
#include "Context.h"

class Context;

class VariableExpression : public BooleanExpression
{
public:
    explicit VariableExpression(const char*);
    virtual ~VariableExpression();

    virtual bool Evaluate(Context&);
    char* getName();

private:
    char* _name;
};
#endif