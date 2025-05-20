#include <iostream>
using namespace std;

int main()
{
  for (int i = 0; i < 5; i++)
  {
    if (i == 2)
    {
      break; // Exit the loop when i is 2
    }
    cout << "The number is: " << i << endl;
  }

  return 0;
}