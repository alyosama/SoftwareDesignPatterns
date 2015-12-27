// Interpreter.cpp : Defines the entry point for the console application.


#include "VariableExpression.h"
#include "BooleanExpression.h"
#include "OrExpression.h"
#include "AndExpression.h"
#include "NotExpression.h"
#include "Constant.h"

int main()
{
    BooleanExpression* expression;
    Context context;

    VariableExpression* x = new VariableExpression("X");
    VariableExpression* y = new VariableExpression("Y");

    expression = new OrExpression(
        new AndExpression (new Constant(true), x),
        new AndExpression (y, new NotExpression(x)));

    context.AssignX(x, true);
    context.AssignY(y, false);

    bool result = expression->Evaluate(context);

    printf("Overall result is %d\n", result);

	return 0;
}

