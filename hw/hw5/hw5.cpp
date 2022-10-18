// Alen Ovalles
// hw5.cpp
// 12-03-2021 (6pm)

// Purpose: Create a struct, read a file, store file contents into an array of struct,
//          do calcuations with the array of structs, print out results
//
// Input: Asks user for 'i', 'r', or 'q' for the input 
// Process: With the given input, call the following function
// Output: Prints either the inventory report, reorder report or the goodbye message 


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 150;
const int STR_SIZE = 20;
const int NUM_SIZE = 15;
const int MIDDLE = 50;
const string REPORT = "p5input.dat";
// given file name 

void welcome();
// Welcome messeage

void readFile();
// Reads and stores the file contents into an array
// Closes the file at the end

int lines(int amount);
// Calculates and returns the amount of lines the file has
// Used to find the size of the array of sturcts if there are blanks

void sorted(int amount);
// Sorted the array of sructs in alphabetical order

void inventory(int amount);
// The function that calculates and prints the inventory report

void reorder(int amount);
// The function that calculates and prints the reorder report

void goodbye();
// Goodbye/shut down message

struct Item
{
  string name;
  string manu;
  int qty;
  int min;
  double cost;
}items[SIZE];

int main()
{
  char response = 'a'; 
  int amount = 0;
    
  welcome();
  readFile();
  amount = lines(amount);
  sorted(amount);
  
  while(response != 'q')
    {
      cout << "Enter..." << endl;
      cout << "'i' for an inventory report" << endl;
      cout << "'r' for an reorder report" << endl;
      cout << "'q' to quit program: ";
      cin >> response;

      if(response == 'i')
        {
          inventory(amount);
        }
      if(response == 'r')
        {
          reorder(amount);
        }
    }
  goodbye();
}
                                                
void welcome()
{
  cout << endl;
  cout << "Welcome to Everything Electronic!" << endl;
  cout << endl;
}

void readFile()
{
  ifstream input;

  input.open(REPORT);
  if(input)
    {
      for(int i = 0; i < SIZE; i++)
        {
          input >> items[i].name >> items[i].manu >> items[i].qty >> items[i].min >> items[i].cost;
        }
    }
  else
    {
      cout << "Error opening the file" << endl;
    }
  input.close();
}

int lines(int amount)
{
  for(int i = 0; i < SIZE; i++)
    {
      if(items[i].name != "")
        {
          amount++;
        }
    }
  return amount;
}

void sorted(int amount)
{
  string tempName;
  string tempManu;
  int tempQty;
  int tempMin;
  double tempCost;

  int startScan, minIndex;

  for(startScan = 0; startScan < (amount - 1); startScan++)
    {
      
      minIndex = startScan;
      tempName = items[startScan].name;
      tempManu = items[startScan].manu;
      tempQty = items[startScan].qty;
      tempMin = items[startScan].min;
      tempCost = items[startScan].cost;

      for(int index = startScan + 1; index < amount; index++)
        {
          if(items[index].name < tempName)
            {
              tempName = items[index].name;
              tempManu = items[index].manu;
              tempQty = items[index].qty;
              tempMin = items[index].min;
              tempCost = items[index].cost;
              minIndex = index;
            }
        }

      items[minIndex].name = items[startScan].name;
      items[minIndex].manu = items[startScan].manu;
      items[minIndex].qty = items[startScan].qty;
      items[minIndex].min = items[startScan].min;
      items[minIndex].cost = items[startScan].cost;

      items[startScan].name = tempName;
      items[startScan].manu = tempManu;
      items[startScan].qty = tempQty;
      items[startScan].min = tempMin;
      items[startScan].cost = tempCost;

    }
}

void inventory(int amount)
{
  cout << endl;

  int diffItems = amount, totalQty = 0;
  double totalCost = 0, cost = 0;

  cout << setw(MIDDLE) << right << "Inventory Report" << endl;
  cout << endl;
  cout << setw(STR_SIZE) << left << "Item";
  cout << setw(STR_SIZE) << left << "Manufacturer";
  cout << setw(NUM_SIZE) << left << "Quantity";
  cout << setw(NUM_SIZE) << left << "Cost Each($)";
  cout << setw(NUM_SIZE) << left << "Total Value($)" << endl;;
  cout << endl;
  
  for(int i = 0; i < amount; i++)
    {
      if(items[i].name != " ")
        {
          cost = items[i].cost * items[i].qty;
          
          cout << setw(STR_SIZE) << left << items[i].name;
          cout << setw(STR_SIZE) << left << items[i].manu;
          cout << setw(NUM_SIZE) << left << items[i].qty;
          cout << setw(NUM_SIZE) << left << setprecision(2) << fixed << items[i].cost;
          cout << setw(NUM_SIZE) << left << setprecision(2) << fixed << cost;
          cout << endl;
          
          totalQty += items[i].qty;
          totalCost += cost;
        }
    }
  
  cout << endl;
  cout << "Number of differnt items: " << diffItems << endl;
  cout << "Total quantity: " << totalQty << endl;
  cout << "Total value of all items: $" << totalCost << endl;
  cout << endl;
}

void reorder(int amount)
{
  cout << endl;

  int diffItems = 0, totalOrder = 0, ordered = 0;
  double cost = 0, totalCost = 0;

  cout << setw(MIDDLE) << right << "Reorder Report" << endl;
  cout << endl;
  cout << setw(STR_SIZE) << left << "Item";
  cout << setw(STR_SIZE) << left << "Manufacturer";
  cout << setw(NUM_SIZE) << left << "Quantity";
  cout << setw(NUM_SIZE) << left << "Minimum";
  cout << setw(NUM_SIZE) << left << "Order";
  cout << setw(NUM_SIZE) << left << "Cost" << endl;;
  cout << endl;
  
  for(int i = 0; i < amount; i++)
    {
      if(items[i].qty < items[i].min)
        {
          ordered = items[i].min - items[i].qty;
          cost = items[i].cost * ordered;
          
          cout << setw(STR_SIZE) << left << items[i].name;
          cout << setw(STR_SIZE) << left << items[i].manu;
          cout << setw(NUM_SIZE) << left << items[i].qty;
          cout << setw(NUM_SIZE) << left << items[i].min;
          cout << setw(NUM_SIZE) << left << ordered;
          cout << setw(NUM_SIZE) << left << setprecision(2) << fixed << cost;
          cout << endl;

          diffItems++;
          totalOrder += ordered;
          totalCost += cost;
        }
    }
  
  cout << endl;
  cout << "Number of different items to order: " << diffItems << endl;
  cout << "Total number to order: " << totalOrder << endl;
  cout << "Total cost: $" << setprecision(2) << fixed << totalCost << endl;
  cout << endl;
}

void goodbye()
{
  cout << endl;
  cout << "Shuting Down . . ." << endl;
  cout << endl;
}

