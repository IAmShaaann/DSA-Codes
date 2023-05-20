#include <iostream>
using namespace std;
class Duck
{
public:
    void Quack(){};
};
class WildDuck : public Duck
{
public:
    void Quack(){};
    void Display(){};
    void Fly(){};
}

class MountainDuck : public WildDuck
{
public:
    void Fly(){};
};

/*

        (0)
    (1) <-> (2)
(3)  (4)  (5)   (6)
The problem here is we can share Algorithmic Solution from parent node to child node,
But not from nodes at same levels.
*/