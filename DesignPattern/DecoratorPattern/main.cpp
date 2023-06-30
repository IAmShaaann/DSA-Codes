#include <iostream>
#include <string>
using namespace std;

class Bevarage
{
public:
    virtual ~Bevarage() {}
    virtual string getDescription() = 0;
    virtual int getCost() = 0;
};

class Espresso : public Bevarage
{
public:
    string getDescription() override
    {
        return "Espresso here";
    }
    int getCost() override
    {
        return 10;
    }
};

class HouseBlend : public Bevarage
{
public:
    string getDescription() override
    {
        return "HouseBlend here";
    }
    int getCost() override
    {
        return 19;
    }
};

class CondimentDecorator : public Bevarage
{
protected:
    Bevarage *beverage;

public:
    CondimentDecorator(Bevarage *beverage)
    {
        this->beverage = beverage;
    }
    string getDescription() override
    {
        return beverage->getDescription();
    }
    int getCost() override
    {
        return beverage->getCost();
    }
};

class Milk : public CondimentDecorator
{
public:
    Milk(Bevarage *beverage) : CondimentDecorator(beverage) {}

    string getDescription() override
    {
        return beverage->getDescription() + ", Milk. ";
    }
    int getCost() override
    {
        return beverage->getCost() + 2;
    }
};

int main()
{

    Bevarage *order_one = new Espresso();
    cout << order_one->getDescription() << endl;

    order_one = new Milk(order_one);
    cout << order_one->getCost() << endl;

    return 0;
}