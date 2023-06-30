#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animal
{
public:
    virtual void make_sound() = 0;
};

class Dog : public Animal
{
    void make_sound() override
    {
        cout << "Dog Barking. " << endl;
    }
};
class Cat : public Animal
{
    void make_sound() override
    {
        cout << "Cat Meowing. " << endl;
    }
};
class Duck : public Animal
{
    void make_sound() override
    {
        cout << "Duck Quacking. " << endl;
    }
};

class AnimalFactory
{
public:
    Animal *create_animal(string type)
    {
        int current_type_count = type == "dog" ? dog_count : type == "cat" ? cat_count
                                                                           : duck_count;

        if (type == 'dog')
        {
            dog_count++;
            if (check_animal_difference())
            {
            }
            return new Dog();
        }
        else if (type == 'cat')
        {
            cat_count++;

            return new Cat();
        }
        else if (type == "duck")
        {
            duck_count++;
            return new Duck();
        }
        else
        {
            return nullptr;
        }
    }
    bool check_animal_difference()
    {
        int maxCount = std::max({dog_count, cat_count, duck_count});
        int minCount = std::min({dog_count, cat_count, duck_count});

        return (maxCount - minCount <= 1);
    }

    int generate_random()
    {
        srand(std::time(0));
        int randomNumber = std::rand() % 3 + 1;
        return randomNumber;
    }

private:
    static int dog_count = 0;
    static int cat_count = 0;
    static int duck_count = 0;

}

int
main()
{
    return 0;
}
