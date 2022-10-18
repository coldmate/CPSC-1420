// Alen Ovalles
// hw2.cpp
// 10-18-2021

// Purpose: Guess that Number Game 
// Input: User inputs the min and max of the range of numbers and a guess between range
// Process: Checks if the guess is higher or lower the random number generated 
// Output: Prints if the guess if higher or lower and asks for another guess 
// Example:
//          Range [1,4] | Guess: 2 | RandNum: 3 | Output: The number is higher  
//          Range [1,6] | Guess: 5 | RandNum: 1 | Output: The number is lower
//          Range [1,3] | Guess: 2 | RandNum: 2 | Output: Wow! You got it on your first guess.


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


/* WELCOME AND RULES*/
void welcomeAndRules()
{
  cout << endl;
  cout << "Welcome to Guess that Number!" << endl;
  cout << "You the player will provide the range for the random number" << endl;
  cout << "If your guess if than the number the code will respond \"higher\"" << endl;
  cout << endl;
}


int main(){
  string play = "y";
  int tries = 1, guess, min, max, randNum;

  while(play == "y")
    {
      welcomeAndRules();
      
      cout << "What is your min: ";
      cin >> min;
  
      cout << "What is your max: ";
      cin >> max;

      cout << "What is your guess: ";
      cin >> guess;

      if(min > max)
        {
        int num = max;
        max = min;
        min = num;
      }

      while((guess < min) or (guess > max))
        {
        cout << "Your guess isn't in your given range " << min << " - " << max << endl;
        cout << "Enter a new guess within the range: ";
        cin >> guess;
      }

      randNum = rand() % (max - min + 1) + min;

      if(guess == randNum){
        cout << "WOW! You guessed it correctly one your first try." << endl;
      }
      else
        {
          while(guess != randNum)
            {
              if(guess > randNum)
                {
                  cout << endl;
                  cout << "The number is lower" << endl;
                  cout << "New guess: ";
                  cin >> guess;
                  cout << endl;
                }
              else
                {
                  cout << endl;
                  cout << "The number is higher" << endl;
                  cout << "New guess: ";
                  cin >> guess;
                  cout << endl;
                }
              tries += 1;
            }
          cout << "Correct, it took " << tries << " guesses." << endl;
        }
      cout << "Would you like to play agian(y/n):  ";
      cin >> play;
      
    }
  cout << "THANKS FOR PLAYING!" << endl;
}

