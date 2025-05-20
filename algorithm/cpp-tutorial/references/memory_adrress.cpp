#include <iostream>
using namespace std;

int main()
{
  string food = "Pizza";
  string &meal = food; // meal is a reference to food

  cout << &food << endl; // Outputs the memory address of food
  cout << &meal << endl; // Outputs the memory address of meal
}