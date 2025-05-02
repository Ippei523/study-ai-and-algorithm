#include <iostream>

int main()
{
  int x, y;
  std::cout << "Enter an integer: ";
  std::cin >> x;
  std::cout << "Enter another integer: ";
  std::cin >> y;

  std::cout << "Sum: " << x + y << std::endl;
  std::cout << "Difference: " << x - y << std::endl;
  std::cout << "Product: " << x * y << std::endl;
  std::cout << "Quotient: " << x / y << std::endl;
  std::cout << "Remainder: " << x % y << std::endl;
  return 0;
}