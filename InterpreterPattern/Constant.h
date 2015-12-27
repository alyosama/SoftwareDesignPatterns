#ifndef CONSTANT_H
#define CONSTANT_H

#include "Constant.h"
#include "Context.h"

class Constant : public BooleanExpression
{
public:
    explicit Constant(bool);
    virtual ~Constant();

    virtual bool Evaluate(Context&);

private:
    bool _operand1;
};
#endif