#include <iostream>
using namespace std;

int main()
{
  int myNumbers[] = {1, 2, 3, 4, 5};
  for (int i : myNumbers)
  {
    cout << i << endl; // Output each element in the array
  }
  return 0;
}