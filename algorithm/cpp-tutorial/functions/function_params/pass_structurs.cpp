#include <iostream>
using namespace std;

struct Car
{
  string brand;
  string model;
  int year;
};

void printCarInfo(Car &car)
{
  cout << "Brand: " << car.brand << ", Model: " << car.model << ", Year: " << car.year << endl;
}

int main()
{
  Car myCar;
  myCar.brand = "Toyota";
  myCar.model = "Corolla";
  myCar.year = 2020;

  printCarInfo(myCar);

  return 0;
}