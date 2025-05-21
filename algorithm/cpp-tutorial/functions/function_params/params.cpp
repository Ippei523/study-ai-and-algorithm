#include <iostream>
using namespace std;

void myFunction(string fname)
{
  cout << fname << " Refsnes" << endl;
}

int main()
{
  myFunction("Liam");
  myFunction("Jenny");
  myFunction("Anja");

  return 0;
}