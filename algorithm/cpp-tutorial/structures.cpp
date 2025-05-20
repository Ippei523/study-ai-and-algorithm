#include <iostream>
using namespace std;

// struct
// {
//   int myNum;
//   string myString;
// } myStructure;

// int main()
// {
//   myStructure.myNum = 1;
//   myStructure.myString = "Hello World";

//   cout << myStructure.myNum << endl;
//   cout << myStructure.myString << endl;

//   return 0;
// }

struct
{
  string brand;
  string model;
  int year;
} myCar1, myCar2, myCar3;

int main()
{
  myCar1.brand = "Ford";
  myCar1.model = "Mustang";
  myCar1.year = 1969;

  myCar2.brand = "BMW";
  myCar2.model = "X5";
  myCar2.year = 1999;

  myCar3.brand = "Toyota";
  myCar3.model = "Corolla";
  myCar3.year = 2005;

  cout << myCar1.brand << " " << myCar1.model << " " << myCar1.year << endl;
  cout << myCar2.brand << " " << myCar2.model << " " << myCar2.year << endl;
  cout << myCar3.brand << " " << myCar3.model << " " << myCar3.year << endl;

  return 0;
}