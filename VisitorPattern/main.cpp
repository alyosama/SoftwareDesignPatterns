#include <iostream>
#include <memory>
#include <string>



template<class T, class U>
std::unique_ptr<T> make_unique(U&& u)
{
    return std::unique_ptr<T>(new T{std::forward<U>(u)});
}

template<class T, class... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T{std::forward<Args>(args)...});
}

class Beef;
class Chicken;
class Necessity;

class Visitor
{
public:
    virtual ~Visitor() = default;
    virtual double visit(std::unique_ptr<Beef> Beef) = 0;
    virtual double visit(std::unique_ptr<Chicken> ChickenItem) = 0;
    virtual double visit(std::unique_ptr<Necessity> necessityItem) = 0;
};

class TaxVisitor : public Visitor
{
public:
    double visit(std::unique_ptr<Beef> BeefItem);
    double visit(std::unique_ptr<Chicken> ChickenItem);
    double visit(std::unique_ptr<Necessity> necessityItem);
};

class TaxHolidayVisitor : public Visitor
{
public:
    double visit(std::unique_ptr<Beef> Beef);
    double visit(std::unique_ptr<Chicken> ChickenItem);
    double visit(std::unique_ptr<Necessity> necessityItem);
};

class Visitable
{
    virtual double accept(Visitor& visitor) = 0;
    ~Visitable() = default;
};

class Beef : public Visitable
{
public:
    Beef(double item) : price(item) { }

    double getPrice() { return price; }

    double accept(Visitor& visitor)
    {
        return visitor.visit(make_unique<Beef>(*this));
    }
private:
    double price;
};

class Chicken : public Visitable
{
public:
    Chicken(double item) : price(item) { }

    double getPrice() { return price; }

    double accept(Visitor& visitor)
    {
        return visitor.visit(make_unique<Chicken>(*this));
    }
private:
    double price;
};

class Necessity : public Visitable
{
public:
    Necessity(double item) : price(item) { }

    double getPrice() { return price; }

    double accept(Visitor& visitor)
    {
        return visitor.visit(make_unique<Necessity>(*this));
    }
private:
    double price;
};

double TaxVisitor::visit(std::unique_ptr<Beef> BeefItem)
{
    std::cout << "Beef item: Price with Tax\n";
    return (BeefItem->getPrice() * .10) + BeefItem->getPrice();
}

double TaxVisitor::visit(std::unique_ptr<Chicken> ChickenItem)
{

    std::cout << "Chicken item: Price with Tax\n";
    return (ChickenItem->getPrice() * .32) + ChickenItem->getPrice();
}

double TaxVisitor::visit(std::unique_ptr<Necessity> necessityItem)
{

    std::cout << "Necessity item: Price with Tax\n";
    return (necessityItem->getPrice() * 0) + necessityItem->getPrice();
}

double TaxHolidayVisitor::visit(std::unique_ptr<Beef> BeefItem)
{
    std::cout << "Beef item: Price with Holiday Tax\n";
    return (BeefItem->getPrice() * .5) + BeefItem->getPrice();
}

double TaxHolidayVisitor::visit(std::unique_ptr<Chicken> ChickenItem)
{

    std::cout << "Chicken item: Price with Holiday Tax\n";
    return (ChickenItem->getPrice() * .4) + ChickenItem->getPrice();
}

double TaxHolidayVisitor::visit(std::unique_ptr<Necessity> necessityItem)
{

    std::cout << "Necessity item: Price with Holiday Tax\n";
    return (necessityItem->getPrice() * 0) + necessityItem->getPrice();
}

//int main()
//{
//    TaxVisitor tax;
//    TaxHolidayVisitor holiday_tax;

//    Beef beef(3.50);
//    Chicken chicken(10.00);
//    Necessity food(53.25);

//    std::cout << "Normal tax:\n";
//    std::cout << beef.accept(tax) << '\n';
//    std::cout << chicken.accept(tax) << '\n';
//    std::cout << food.accept(tax) << std::endl;

//    std::cout << "\nHoliday tax:\n";
//    std::cout << beef.accept(holiday_tax) << '\n';
//    std::cout << chicken.accept(holiday_tax) << '\n';
//    std::cout << food.accept(holiday_tax) << std::endl;
//}
