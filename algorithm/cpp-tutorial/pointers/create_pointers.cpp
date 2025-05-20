#include <iostream>
using namespace std;

int main()
{
  string food = "Pizza";
  string *ptr = &food; // Create a pointer to the string variable

  cout << "Food: " << food << endl;                         // Output the value of the string variable
  cout << "Pointer: " << *ptr << endl;                      // Output the value of the string variable using the pointer
  cout << "Address of food: " << &food << endl;             // Output the address of the string variable
  cout << "Address of pointer: " << ptr << endl;            // Output the address stored in the pointer
  cout << "Address of pointer (using &): " << &ptr << endl; // Output the address of the pointer itself

  string *ptr2 = new string("Burger");                                 // Dynamically allocate memory for a string
  string *ptr3 = new string("Pasta");                                  // Dynamically allocate memory for another string
  string *ptr4 = new string("Salad");                                  // Dynamically allocate memory for another string
  cout << "Dynamically allocated string: " << *ptr2 << endl;           // Output the value of the dynamically allocated string
  cout << "Dynamically allocated string: " << *ptr3 << endl;           // Output the value of the dynamically allocated string
  cout << "Dynamically allocated string: " << *ptr4 << endl;           // Output the value of the dynamically allocated string
  cout << "Address of dynamically allocated string: " << ptr2 << endl; // Output the address of the dynamically allocated string
  cout << "Address of dynamically allocated string: " << ptr3 << endl; // Output the address of the dynamically allocated string
  cout << "Address of dynamically allocated string: " << ptr4 << endl; // Output the address of the dynamically allocated string
}