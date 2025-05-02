#include <iostream>

int main()
{
  int x = 5, y = 10, z = 15; // Declare and initialize multiple variables
  std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;

  int a, b, c;    // Declare multiple variables
  a = b = c = 20; // Assign a value to the last variable
  std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
  return 0;
}