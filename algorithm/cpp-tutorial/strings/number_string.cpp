#include <iostream>
#include <string>

int main()
{
  std::string str1 = "10";
  int num1 = 20;

  std::string str2 = str1 + num1;
  std::cout
      << "Concatenated String: " << str2 << std::endl;
}
