#ifndef NOTEXPRESSION_H
#define NOTEXPRESSION_H

#include "NotExpression.h"
#include "Context.h"

class NotExpression : public BooleanExpression
{
public:
    explicit NotExpression(BooleanExpression*);
    virtual ~NotExpression();

    virtual bool Evaluate(Context&);

private:
    BooleanExpression* _operand1;
};
#endif