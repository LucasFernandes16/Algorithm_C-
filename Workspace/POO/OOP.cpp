#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player{
private:
  string name{"Player"};
  int health;
  int xp;
public:
  Player(std::string name_val = "None", int health = 0, int xp_val = 0);
};

Player::Player(std::string name_val, int health_val, int xp_val)
  :name{name_val},health{health_val},xp{xp_val}{
    cout << "Three-args" << endl;
  }

int main(){

  Player empty;
  Player frank{"Frank"};
  Player hero{"Hero", 100};
  Player vilain{"Villain", 100, 55};
/*
  Account frank_account;
  Account jimmy_account;

  Player frank;
  Player hero;

  Player players[] {frank,hero};

  vector<Player> player_vec{frank};
  player_vec.push_back(hero);

  Player *enemy{nullptr};
  enemy = new Player;

  delete enemy;
  */
  return 0;
 }