#include <iostream>
#include <cmath> // For math functions
using namespace std;

int main()
{
  // Basic arithmetic operations
  int a = 10, b = 20;
  cout << "Addition: " << (a + b) << endl;
  cout << "Subtraction: " << (a - b) << endl;
  cout << "Multiplication: " << (a * b) << endl;
  cout << "Division: " << (b / a) << endl;
  cout << "Modulus: " << (b % a) << endl;

  // Using cmath library for advanced math functions
  double x = 16.0;
  cout << "Square root of " << x << ": " << sqrt(x) << endl;
  cout << "Power of 2^3: " << pow(2, 3) << endl;
  cout << "Sine of 30 degrees: " << sin(30 * M_PI / 180) << endl;   // Convert degrees to radians
  cout << "Cosine of 60 degrees: " << cos(60 * M_PI / 180) << endl; // Convert degrees to radians

  return 0;
}