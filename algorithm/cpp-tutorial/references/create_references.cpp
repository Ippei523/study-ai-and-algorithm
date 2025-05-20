#include <iostream>
using namespace std;

int main()
{
  string food = "Pizza";
  string &meal = food; // meal is a reference to food

  cout << "Original food: " << food << endl;  // Outputs Pizza
  cout << "Reference meal: " << meal << endl; // Outputs Pizza

  meal = "Burger";                                 // Changing the reference also changes the original variable
  cout << "After changing food: " << food << endl; // Outputs Burger
  cout << "After changing meal: " << meal << endl; // Outputs Burger
}