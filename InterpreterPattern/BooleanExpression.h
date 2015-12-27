#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

class Context;

class BooleanExpression
{
public:
    explicit BooleanExpression(void);
    virtual ~BooleanExpression(void);

    virtual bool Evaluate(Context&) = 0;
};
#endif