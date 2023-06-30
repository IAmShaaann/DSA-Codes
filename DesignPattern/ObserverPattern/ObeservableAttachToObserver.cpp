#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Observer; // Empty Class

class Observable // Subject to be observed
{

    vector<Observer *> observers; // vector for observers.
    int state;

public:
    void attach(Observer *observer) // Attach observer to the Observable/Subject.
    {
        observers.push_back(observer);
    }

    void detach(Observer *observer) // Detach observer to the Observale/Subject.
    {
        for (auto it = observers.begin(); it != observers.end(); it++)
        {
            if (*it == observer)
            {
                observers.erase(it);
                break;
            }
        }
    }

    void setState(int state) // As soon as the state changes, We notify the observers.
    {
        this->state = state;
        notify();
    }

    int getState() const
    {
        return state;
    }

    void notify();
};

class Observer // Observer Takes, an Observable to whom it is required to attach to.
{
protected:
    Observable *Subject;

public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Observable *subject) // Constructure takes an Observable parameter and attaches it to the observer.
    {
        this->Subject = subject;
        Subject->attach(this);
    }

    void update() override
    {
        cout << "Subject State changed : " << this->Subject->getState() << endl;
    }
};

void Observable::notify() // Notify the observer and update the observer state to new one.
{
    for (Observer *observer : observers)
    {
        observer->update();
    }
}

int main()
{
    Observable subject;
    ConcreteObserver observer(&subject);
    subject.setState(10);

    return 0;
}
