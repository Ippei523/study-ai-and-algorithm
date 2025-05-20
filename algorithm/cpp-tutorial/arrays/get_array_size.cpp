#include <iostream>
using namespace std;

int main()
{
  int myNumbers[] = {10, 20, 30, 40, 50};

  cout << "Size of myNumbers: " << sizeof(myNumbers) << endl;
  cout << "Size of myNumbers[0]: " << sizeof(myNumbers) / sizeof(myNumbers[0]) << endl;

  for (int i = 0; i < 5; i++)
  {
    cout << "Element at index " << i << ": " << myNumbers[i] << endl;
  }

  for (int i = 0; i < sizeof(myNumbers) / sizeof(myNumbers[0]); i++)
  {
    cout << "Element at index " << i << ": " << myNumbers[i] << endl;
  }
}