class BooleanExpression
{
public:
    BooleanExpression(void);
    virtual ~BooleanExpression(void);

    virtual bool Evaluate(Context&) = 0;
};

class VariableExpression : public BooleanExpression
{
public:
    VariableExpression(const char*);
    virtual ~VariableExpression();

    virtual bool Evaluate(Context&);
    char* getName();

private:
    char* _name;
};

class Context
{
public:
    Context(void);
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

class NotExpression : public BooleanExpression
{
public:
    NotExpression(BooleanExpression*);
    virtual ~NotExpression();

    virtual bool Evaluate(Context&);
//    virtual BooleanExpression* Replace;
//    virtual BooleanExpression* Copy() const;

private:
    BooleanExpression* _operand1;
};

class OrExpression : public BooleanExpression
{
public:
    OrExpression(BooleanExpression*, BooleanExpression*);
    virtual ~OrExpression();

    virtual bool Evaluate(Context&);
//    virtual BooleanExpression* Replace;
//    virtual BooleanExpression* Copy() const;

private:
    BooleanExpression* _operand1;
    BooleanExpression* _operand2;
};