// Alen Ovalles
// hw1.cpp
// 10-08-2021

// Purpose: Enter given inputs to fill the blanks of the constructive story
// Inputs: Nouns, plural nouns, adjectives, school, person's name, and a body part
// Processing: Stores user's creative choices in respected variables
// Output: A story with the user's input (MadLib)
// Example:
//          INPUT
//          Num = 5, Name = Collion, Place = Idaho, Animal = tiger
//
//          OUTPUT
//          Collion was in Idaho for the summer, and saw 5 tigers out in the wild.
//

#include <iostream>
#include <string>

using namespace std;

/*------UNIVERSAL_VARIABLES-------*/
string school, adj1, plurNoun1, person, bodyPart, clothing, plurNoun2, noun1, noun2, adj2, adj3, plurNoun3;
int num;

void blanks(int amount) // prints (x) amount of blank lines
{ 
  for(int i = 0; i < amount; i++)
    {
      cout << endl;
  }
}

void welcomeMessage() // welcome message function
{ 
  blanks(3);
  cout << "Welcome to Madlibs, Prompt: Report by Student Protest Committee";
}

void userInput() // a function asking for the user's input
{ 
  blanks(3);
 
  cout << "Enter a school: ";
  getline(cin, school);
  
  cout << "Enter an adjective: ";
  getline(cin, adj1);

  cout << "Enter a plural noun: ";
  getline(cin, plurNoun1);

  cout << "Enter a person's name: ";
  getline(cin, person);

  cout << "Enter a part of the body: ";
  getline(cin, bodyPart);

  cout << "Enter an article of clothing: ";
  getline(cin, clothing);

  cout << "Enter another plural noun: ";
  getline(cin, plurNoun2);
    
  cout << "Enter a noun: ";
  getline(cin, noun1);
 
  cout << "Enter another noun: ";
  getline(cin, noun2);

  cout << "Enter another adjective: ";
  getline(cin, adj2);

  cout << "Enter another adjective: ";
  getline(cin, adj3);

  cout << "Enter another plural noun: ";
  getline(cin, plurNoun3);

  cout << "Enter an integer: ";
  cin >> num;
  
  blanks(3);
}

void userOutput() // the story with given user inputs
{
  cout << "Fellow Students of " << school << "!" << endl;
  
  cout << "We the members of the Students for a/an " << adj1 << " Society are meeting here at to decide what action to take about ";
  cout << "the Dean of " << plurNoun1 << "." << endl;
  
  cout << "He has just fired our friend, Professor " << person << ", because he wore his " << bodyPart << " long, and ";
  cout << "because he dressed in a/an " << clothing << " and wore old " << plurNoun2 << "." << endl;

  cout << "Next weeks, we are going to protest for " << num << " hours by taking over the ";
  cout << noun1 << " building and kidnapping the Assistant " << noun2 << "." << endl;

  cout << "We will also demand that all students have the right to wear " << adj2 << " hair and ";
  cout << adj3 << " beards. Remember out solgan: \"Down with " << plurNoun3 << "." << endl;
}

void goodbyeMessage() // goodbye message functions
{ 
  blanks(3); 
  cout << "Thanks for playing MabLibs." << endl;
  blanks(1);
}

int main ()
{
  /*------WELCOME------*/
  welcomeMessage();

  /*------INPUT------*/
  userInput();

  /*------OUTPUT------*/
  userOutput();

  /*------GOODBYE------*/
  goodbyeMessage();  
}
