#include <stdio.h>
#include "AndExpression.h"

AndExpression::AndExpression(BooleanExpression* op1, BooleanExpression* op2)
{
    _operand1 = op1;
    _operand2 = op2;
}

AndExpression::~AndExpression(void)
{
}

bool AndExpression::Evaluate(Context& aContext)
{
    bool oper1Eval = _operand1->Evaluate(aContext);
    bool oper2Eval = _operand2->Evaluate(aContext);

    printf("And expression parameters: %d %d\n", oper1Eval, oper1Eval);
    printf("And expression result: %d\n", oper1Eval && oper1Eval);

    return
        oper1Eval &&
        oper2Eval;
}