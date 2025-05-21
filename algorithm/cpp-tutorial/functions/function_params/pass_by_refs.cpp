#include <iostream>
using namespace std;

void swapNumbs(int &x, int &y)
{
  int z = x;
  x = y;
  y = z;
}

int main()
{
  int firstNum = 5;
  int secondNum = 10;

  cout << "Before swap: " << firstNum << " " << secondNum << endl;
  swapNumbs(firstNum, secondNum);
  cout << "After swap: " << firstNum << " " << secondNum << endl;
  // Output:
  // Before swap: 5 10
  // After swap: 10 5
}