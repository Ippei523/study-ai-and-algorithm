#include <iostream>
using namespace std;

// int myFunction(int x, int y)
// {
//   return x + y;
// }

// int main()
// {
//   int sum = myFunction(5, 3);
//   cout << "The sum is: " << sum << endl;

//   return 0;
// }

int doubleFunction(int x)
{
  return x * 2;
}

int main()
{
  for (int i = 1; i <= 5; i++)
  {
    cout << "double of " << i << " is " << doubleFunction(i) << endl;
  }

  return 0;
}
