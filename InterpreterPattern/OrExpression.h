#ifndef OREXPRESSION_H
#define OREXPRESSION_H

#include "BooleanExpression.h"
#include "Context.h"

class OrExpression : public BooleanExpression
{
public:
    explicit OrExpression(BooleanExpression*, BooleanExpression*);
    virtual ~OrExpression();

    virtual bool Evaluate(Context&);

private:
    BooleanExpression* _operand1;
    BooleanExpression* _operand2;
};
#endif