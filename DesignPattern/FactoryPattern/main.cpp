#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IGameObject
{
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane() {}
    void Update() {}
    void Render() {}
};

class Boat : public IGameObject
{
public:
    Boat() {}
    void Update() {}
    void Render() {}
};

enum class GameObjectType
{
    BOAT,
    PLANE
};

class GameObjectFactory
{
public:
    // Making function static will ensure all objects of this class share the same function.
    static shared_ptr<IGameObject> CreateObject(GameObjectType type)
    {
        if (GameObjectType::PLANE == type)
        {
            s_count_plane_instance++;
            return make_shared<Plane>();
        }
        else if (GameObjectType::BOAT == type)
        {
            s_count_boat_instance++;
            return make_shared<Boat>();
        }
        return nullptr;
    }
    static void print_instance_count(GameObjectType type)
    {
        if (GameObjectType::PLANE == type)
        {
            cout << "Plane instance count. " << s_count_plane_instance << endl;
        }
        else if (GameObjectType::BOAT == type)
        {
            cout << "Boat instance count. " << s_count_boat_instance << endl;
        }
    }

private:
    GameObjectFactory() {}
    ~GameObjectFactory() {}
    GameObjectFactory(GameObjectFactory &game_instance) = delete;
    static int s_count_boat_instance;
    static int s_count_plane_instance;
};

int GameObjectFactory::s_count_boat_instance = 0;
int GameObjectFactory::s_count_plane_instance = 0;

int main()
{
    shared_ptr<IGameObject> game_instance_one = GameObjectFactory::CreateObject(GameObjectType::PLANE);
    shared_ptr<IGameObject> game_instance_two = GameObjectFactory::CreateObject(GameObjectType::BOAT);
    shared_ptr<IGameObject> game_instance_three = GameObjectFactory::CreateObject(GameObjectType::PLANE);

    GameObjectFactory::print_instance_count(GameObjectType::PLANE);
    GameObjectFactory::print_instance_count(GameObjectType::BOAT);

    return 0;
}