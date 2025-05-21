#include <iostream>
using namespace std;

void myFunction(string fname, int age)
{
  cout << "Name: " << fname << ", Age: " << age << endl;
}
int main()
{
  myFunction("Liam", 25);
  myFunction("Jenny", 30);
  myFunction("Anja", 22);

  return 0;
}