#include <iostream>
using namespace std;

int main()
{
  string cars[5];
  cars[0] = "Volvo";
  cars[1] = "BMW";
  cars[2] = "Ford";
  cars[3] = "Mazda";
  cars[4] = "Toyota";
  cout << cars[0] << endl; // Outputs Volvo
  cout << cars[1] << endl; // Outputs BMW

  cout << cars << endl; // Outputs the address of the array
}