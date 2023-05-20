#include <bits/stdc++.h>
using namespace std;

struct Player
{ // Player indentity["Name"] -> X,y coords for moving in the game.
  int x;
  int y;
  string name;

  Player(string _name)
  {
    name = _name;
    cout << "Welcome, " << name << endl;
  }

  void move(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
};

class Command
{
public:
  virtual ~Command() {}
  virtual void execute(Player &player) = 0;
  virtual void undo(Player &player) = 0; // Will do opposite of execute().
};

class Move : public Command
{
public:
  Move()
  {
    srand(time(NULL)); // Seed the random number generator.
  }

  void execute(Player &player)
  {
    int random_x = rand() % 1000;
    int random_y = rand() % 1000;

    player.move(random_x, random_y); // Move the player

    x = random_x;
    y = random_y;

    cout << player.name << " moved " << x << ", " << y << endl;
  }

  void undo(Player &player)
  {
    player.move(-x, -y); // Move the player back.
    cout << player.name << " moved back " << -x << ", " << -y << endl;
  }

private:
  int x;
  int y;
};

int main()
{

  Player player("Rohit");

  vector<Command *> command_queue; // vector to store commands

  for (int i = 0; i < 4; i++)
  { // Add four moves to the command queue.
    Move *move = new Move;
    command_queue.push_back(move);
  }

  for (const auto &command : command_queue)
  { // Run execute function.
    command->execute(player);
  }

  for (auto it = command_queue.rbegin(); it != command_queue.rend(); ++it)
  { // Run undo function
    (*it)->undo(player);
  }

  return 0;
}