#include <iostream>

int main()
{
  const int consumptionTaxInJapan = 10; // Consumption tax in Japan

  consumptionTaxInJapan = 8; // This will cause a compilation error because consumptionTaxInJapan is a constant
}