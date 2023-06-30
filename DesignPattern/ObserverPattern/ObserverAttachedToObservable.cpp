#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Observer // Clients/onservers that keep an eye on the client.
{
public:
    virtual void update(int value) = 0;
};

class Observable // Subject to keep an eye on.
{
private:
    int state;
    vector<Observer \*> observers; // Subject can have multiple observers.

public:
    void attach(Observer *observer) // Each observer has to be attached to a subject.
    {
        observers.push_back(observer);
    }
    void detach(Observer *obserser) // Detaching a observer from a subject
    {
        for (auto it = observers.begin(); it != observers.end(); it++)
        {
            if (\* it == obserser)
            {
                observers.erase(it);
                break;
            }
        }
    }

    void setState(int state) // Changing state and notifying the observers.
    {
        this->state = state;
        notify();
    }
    void notify()
    {
        for (Observer *observer : observers)
        {
            observer->update(state);
        }
    }
};
class ConcreteObserver : public Observer // child class
{
private:
    string name;

public:
    ConcreteObserver(const std::string &name) : name(name) {} // default constructure
    void update(int value) override                           // virtual function from parent class.
    {
        cout << "Observer value updated to: " << value << endl;
    }
};

int main()
{

    Observable observable; // Client Parent Class.
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");

    observable.attach(&observer1); // observers being attached to the subject.
    observable.attach(&observer2);

    observable.setState(10); // changing the state -> this will notify the observers.
    observable.setState(20);

    observable.detach(&observer1); // detaching the observer from the subject.

    observable.setState(30);

    return 0;
}

// When you add a concrete keyword before a class name it means it is a parent class that is inheriting some interface.
