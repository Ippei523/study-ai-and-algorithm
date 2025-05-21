#include <iostream>
using namespace std;

int plusFunc(int x, int y)
{
  return x + y;
}

double plusFunc(double x, double y)
{
  return x + y;
}

int main()
{
  int intResult = plusFunc(5, 3);
  double doubleResult = plusFunc(5.5, 3.2);

  cout << "Integer result: " << intResult << endl;   // Output: Integer result: 8
  cout << "Double result: " << doubleResult << endl; // Output: Double result: 8.7

  return 0;
}