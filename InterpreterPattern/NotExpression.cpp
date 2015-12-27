#include <stdio.h>
#include "NotExpression.h"

NotExpression::NotExpression(BooleanExpression* op1)
{
    _operand1 = op1;
}

bool NotExpression::Evaluate(Context& aContext)
{
    bool operEval = !_operand1->Evaluate(aContext);

    printf("Not expression parameters: %d\n", _operand1->Evaluate(aContext));
    printf("Not expression result: %d\n", operEval);

    return
        operEval;
}

NotExpression::~NotExpression(void)
{
}