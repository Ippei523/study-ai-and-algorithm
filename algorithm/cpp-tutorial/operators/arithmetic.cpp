#include <iostream>

int main()
{
  int sum1 = 150;
  int sum2 = sum1 + 250;
  int sum3 = sum1 + sum2;

  std::cout << "Sum1: " << sum1 << std::endl;
  std::cout << "Sum2: " << sum2 << std::endl;
  std::cout << "Sum3: " << sum3 << std::endl;
}