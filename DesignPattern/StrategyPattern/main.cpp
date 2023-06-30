#include <iostream>
using namespace std;
class Duck // parent class
{
public:
    virtual void display() = 0;
    virtual void quack() = 0;
    virtual void fly() = 0;
};

class MountainDuck : public Duck // child class overriding the methods of parent class.
{
    void display() override
    {
        cout << "MountainDuck Display." << endl;
    }
    void quack() override
    {
        cout << "MountainDuck Quack." << endl;
    }
    void fly() override
    {
        cout << "MountainDuck Fly." << endl;
    }
};

class FlyBehavior // another parent class or interface
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior // child class inheriting and overriding features of parent class.
{
public:
    void fly() override
    {
        cout << "Flying With Wings" << endl;
    }
};

class FlyWithoutWings : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I was thrown." << endl;
    }
};

class RubberDuck : public Duck // Child class
{
private:
    FlyBehavior *flyBehavior; // class type priavte variable

public:
    RubberDuck(FlyBehavior *flyBehavior) // constructor taking class type variable argument. With/WhitoutWings
    {
        this->flyBehavior = flyBehavior;
    }
    void display() override
    {
        cout << "Rubber Duck. " << endl;
    }
    void quack() override
    {
        cout << "Squeck Squeck. " << endl;
    }
    void fly() override
    {
        flyBehavior->fly(); // overriding the function with interface's method behavior. based upon the type of class param provided to us
        // fly method will change accordingly
    }
};

int main()
{
    // as this is an instance Duck type and initialized with MountainDuck class
    //  this will call methods of the MountainDuck class

    Duck *mountainDuck = new MountainDuck();
    mountainDuck->display();
    mountainDuck->quack();
    mountainDuck->fly();

    FlyBehavior *rubberDuckFlyBehavior = new FlyWithoutWings(); // as this is a FlyBehavior type variable this will by default have a fly method.
    // We have 2 child classes FlyWithWings and FlyWithoutWing  based upon the object created for
    // what class the fly method will be called.
    Duck *rubberDuck = new RubberDuck(rubberDuckFlyBehavior);
    // as this RubberDuck is taking a class based parameter We assign this param to a private variable to RubberDuck class
    rubberDuck->display();
    rubberDuck->quack();
    rubberDuck->fly(); // fly method o

    delete mountainDuck;
    delete rubberDuck;
    delete rubberDuckFlyBehavior;

    return 0;
}

// In this Design Pattern we can change and run different method provided different conditions.
