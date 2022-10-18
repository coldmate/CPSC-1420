// Alen Ovalles
// hw3.cpp
// 11-05-2021

// Purpose: Game of Chutes and Ladders | 2 players
// Input: "Spins" dice
// Process: calculates if player hit a ladder/chute/nothing
// Output: new player location, and if won
// Example:
//
//
// Welcome to the chutes and ladders gmae. Both players start at o, end the first one to 100 wins the game
// player1: ties your turn | you rolled # | your new location is: # | You landed on ladders, and get to move up the board:
//                                                                    You landded on chutes, and have to move down 
// player # name won!
//


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcome();
// welcome message

void goodBye();
// goodbye message

void turn(string playerName, int playerRoll, int &playerSqrt);
// calculates each player's turn

int ladder(int playerRoll);
// returns num > 0 if player hit a ladder

int chute(int playerRoll);
// return num < 0 if player hit a chute

string lowercase(string answer);
// changes all uppercase char to lowercase

string uppercase(string name);
// changes first char of player's name to uppercase if it isn't

int main()
{

  string replay = "yes", player1Name, player2Name;

  welcome();
  cout << endl;
  cout << "Please enter player1's name: ";
  cin >> player1Name;
  player1Name = uppercase(player1Name);
  
  cout << "Please enter player2's name: ";
  cin >> player2Name;
  player2Name = uppercase(player2Name);
  cout << endl;


  while(replay == "yes" or replay == "y")
    {

      // VARIABLES
      int player1Sqrt = 0, player2Sqrt = 0, player1Roll, player2Roll;
      bool running = true;

      srand(time(NULL));

      // MAIN GAME LOOP
      while(running)
        {

          player1Roll = rand() % (6 - 1 + 1) + 1;

          player2Roll = rand() % (6 - 1 + 1) + 1;

          player1Sqrt += player1Roll;
          player2Sqrt += player2Roll;

          // Player 1
          turn(player1Name, player1Roll, player1Sqrt);

          // after called function
          if(player1Sqrt == 100)
            {
              cout << "Player 1 " << player1Name << " won!!" << endl;
              running = false;
            }
          else
            {
              cout << endl;
            }
          
          // Player 2
          if(running == true)
            {
              turn(player2Name, player2Roll, player2Sqrt); // Can't pass in a (str, int, int, bool) ??

              // after called function
              if(player2Sqrt == 100)
                {
                  cout << "Player 2 " << player2Name << " won!!" << endl;
                  running = false;
                }
              else
                {
                  cout << endl;
                }
            }            
        }
      cout << endl << endl << endl;
      cout << "Do you want to play again(y/n): ";
      cin >> replay;
      replay = lowercase(replay);

    }
  goodBye();
}

void turn(string playerName, int playerRoll, int &playerSqrt)
{
  int newSqrt;
  int lad;
  int chut;

  newSqrt = playerSqrt;
  lad = ladder(newSqrt);
  chut = chute(newSqrt);

  cout << playerName << ": Its your turn." << endl;
  cout << "You rolled " << playerRoll << endl;

  if(lad > 0)
    {
      cout << "You landed on ladders, and get to move up the board!" << endl;
      playerSqrt = newSqrt + lad;
      cout << "Your new location is: " << playerSqrt << endl;
    }
  else if(chut < 0)
    {
      cout << "You landed on chutes, and have to move down" << endl;
      playerSqrt = newSqrt + chut;
      cout << "Your new location is: " << playerSqrt << endl;
    }

  else if(newSqrt > 101)
    {
      cout << "The spin is ignored because the result will past 100" << endl;
      playerSqrt -= playerRoll;
    }
  else
    {
      cout << "Your new location is: " << playerSqrt << endl;
    }
}

string lowercase(string answer)
{
  string str = answer;
  int size = str.length();

  for(int i = 0; i < size; i++)
    {
      if(islower(str[i]) == false)
        {
          str[i] = str[i] + 32;
        }
    }
  return str;
}

string uppercase(string name)
{
  string str = name;
  int size = str.length();

  for(int i = 0; i < size; i++)
    {
      if(i == 0)
        {
          if(isupper(str[i]) == false)
            {
              str[i] = str[i] - 32;
            }
        }
      else
        {
          if(islower(str[i]) == false)
            {
              str[i] = str[i] + 32;
            }
        }
    }
  return str;
}

int ladder(int playerRoll)
{
  int num = 0;

  if(playerRoll == 1)
    {
      num = 37;
    }
  else if(playerRoll == 4)
    {
      num = 10;
    }
  else if(playerRoll == 9)
    {
      num = 12;
    }
  else if(playerRoll == 23)
    {
      num = 21;
    }
  else if(playerRoll == 28)
    {
      num = 56;
    }
  else if(playerRoll == 36)
    {
      num = 8;
    }
  else if(playerRoll == 51)
    {
      num = 15;
    }
  else if(playerRoll == 71)
    {
      num = 19;
    }
  else if(playerRoll == 80)
    {
      num = 20;
    }
  else
    {
      num = 0;
    }
  return num;
}

int chute(int playerRoll)
{
  int num = 0;

  if((playerRoll == 98) or (playerRoll == 95) or (playerRoll == 93))
    {
      num = -20;
    }
  else if(playerRoll == 87)
    {
      num = -63;
    }
  else if(playerRoll == 64)
    {
      num = -4;
    }
  else if(playerRoll == 62)
    {
      num = -43;
    }
  else if(playerRoll == 56)
    {
      num = -3;
    }
  else if(playerRoll == 49)
    {
      num = -38;
    }
  else if(playerRoll == 48)
    {
      num = -22;
    }
  else if(playerRoll == 16)
    {
      num = -10;
    }
  else
    {
      num = 0;
    }
  return num;
}

void welcome()
{
  cout << endl;
  cout << "Welcome to chutes and ladders game. Both" << endl;
  cout << "players start at 0, and the first one to 100" << endl;
  cout << "wins the game." << endl;
}

void goodBye()
{
  cout << endl << endl << endl;
  cout << "Thanks for playing!" << endl;
  cout << endl;
}
