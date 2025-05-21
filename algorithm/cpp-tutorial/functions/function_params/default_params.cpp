#include <iostream>
using namespace std;

void myFunction(string country = "Norway")
{
  cout << country << endl;
}

int main()
{
  myFunction("Sweden");
  myFunction("Finland");
  myFunction();
  myFunction("Iceland");
  return 0;
}