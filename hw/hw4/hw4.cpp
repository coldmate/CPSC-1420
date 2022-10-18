// Alen Ovalles
// hw4.cpp
// 10-19-2021 (6pm)

// Purpose: Using two-dimensional arrays with file reading and calling functions
// Input: Enter a row and col; Enter another row and another col: 
// Process: Checks if the row and col are valid and shows a card
// Output: Prints the array with shown card; if matched change element to a '-'
// Example: row1 and col1: 1 1 | A
//          row2 and col2: 0 3 | A
//          "The cards match" | arr[row1][col1] = '-'
//                              arr[row2][col2] = '-'


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

const int ROW = 3;
const int COL = 4;
const string FILE1 = "p4data1.dat";
const string FILE2 = "p4data2.dat";
const int WAIT = 5;

void welcome();
// Welcome message

void goodbye();
// Goodbye message 

void wait(int seconds);
// Pause function if cards don't match

void readFile(string fileNum, char cards[][COL]);
// Reads the given file context

string randFile();
// Choice and returns one of the two files

void validIndex(int& row, int& col, char board[][COL]);
// Checks if the first user input(row1 and col1) is a valid index to choose

void validElement(int row1, int col1, int& row2, int& col2, char board[][COL]);
// Checks if the element in the index isn't already found

void print(char board[][COL]);
// Prints the array

void check(char card1, char card2, char board[][COL], int& pairs, int row1, int col1, int row2, int col2);
// Checks if the card1 and card2 are mathcing
// If they are replace cards with dashes('-'); if not replace with stars('*')

char swap(int row, int col, char cards[][COL], char board[][COL]);
// Swaps in the choosen card with the star to the same index

int main ()
{
  cout << endl;
  
  char card1;
  char card2;
  int score = 0;
  int row1, col1, row2, col2;
  int pairs;
  string replay = "yes";
  
  char board[ROW][COL] = {{'*', '*', '*', '*'}, {'*', '*', '*', '*'}, {'*', '*', '*', '*'}};
  char cards[ROW][COL];
  
  while(replay == "yes")
    {
      pairs = 0;
        
      readFile(randFile(), cards);

      welcome();
      cout << endl;

      while(pairs < 6)
        {
          print(board);
          
          cout << endl;
          cout << "Pick a row and col: ";
          cin >> row1 >> col1;
          
          validIndex(row1, col1, board);
          card1 = swap(row1, col1, cards, board);
          print(board);
          
          cout << "Pick another row and another col: ";
          cin >> row2 >> col2;
          
          validIndex(row2, col2, board);
          validElement(row1, col1, row2, col2, board);
          card2 = swap(row2, col2, cards, board);
          print(board);

          check(card1, card2, board, pairs, row1, col1, row2, col2);

          score++;
          cout << endl;
        }
      cout << "You win! the score is " << score << endl;
      cout << endl;
      cout << "Do you want the play again? ";
      cin >> replay;
    }
  
  goodbye();
  
}

void validElement(int row1, int col1, int& row2, int& col2, char board[][COL])
{
  while((row1 == row2) && (col1 == col2))
    {
      cout << "This card can't be the same as the first" << endl;
      cout << "Pick another row and another col: ";
      cin >> row2 >> col2;
      validIndex(row2, col2, board);
      cout << endl;
    }
}

void wait(int seconds)
{
  clock_t endwait; 
  endwait = clock() + seconds * CLOCKS_PER_SEC; 
 
  while (clock() < endwait)  
  {  
  }
}

void check(char card1, char card2, char board[][COL], int& pairs, int row1, int col1, int row2, int col2)
{
  if(card1 == card2)
    {
      cout << endl;
      cout << "The two cards match and are removed" << endl;      
      board[row1][col1] = '-';
      board[row2][col2] = '-';
      pairs++;         
    }
  else
    {
      cout << endl;
      cout << "The two cards doesn't match" << endl;
      cout << "Pausing for 5 seconds" << endl;
      wait(WAIT);
      board[row1][col1] = '*';
      board[row2][col2] = '*';
    }
}

void print(char board[][COL])
{
  for(int row = 0; row < ROW; row++)
    {
      for(int col = 0; col < COL; col++)
        {
          cout << setw(3) << board[row][col];
        }
      cout << endl;
    }
}

char swap(int row, int col, char cards[][COL], char board[][COL])
{
  char card;
  card = cards[row][col];
  board[row][col] = card;
  return card;
}

void validIndex(int& row, int& col, char board[][COL])
{
  while(board[row][col] == '-')
    {
      cout << "The card is already removed, pls choose again" << endl;
      cout << "Pick another row and another col: ";
      cin >> row >> col;
      cout << endl;
    }
}

void welcome()
{
  cout << "Welcome to play the memory game!" << endl;
}

void goodbye()
{
  cout << endl;
  cout << "Thanks for Playing!" << endl;
  cout << endl;
}

string randFile()
{
  int randNum = rand() % (1 - 0 + 1) + 0;
  if(randNum == 0)
    {
      return FILE1;
    }
  else
    {
      return FILE2;
    }
}

void readFile(string fileName, char arr[][COL])
{
  ifstream input;
  char card;

  input.open(fileName);
  if(input)
    {
      for(int i = 0; i < ROW; i++)
        {
          for(int j = 0; j < COL; j++)
            {
              input >> card;
              arr[i][j] = card;
            }
        }
    }
  else
    {
      cout << "Error opening the file" << endl;
    }
  input.close();
}
