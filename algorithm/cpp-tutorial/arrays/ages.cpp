#include <iostream>
using namespace std;

int main() {
  int ages[8] = {18, 20, 22, 25, 30, 35, 40, 45};
  int sum = 0;

  int length = sizeof(ages) / sizeof(ages[0]);

  for (int i = 0; i < sizeof(ages) / sizeof(ages[0]); i++) {
    sum += ages[i];
  }

  cout << "Sum of ages: " << sum << endl;
  cout << "Average age: " << sum / length << endl;

  int lowestAge = ages[0];
  int highestAge = ages[0];

  for (int i = 1; i < length; i++) {
    if (ages[i] < lowestAge) {
      lowestAge = ages[i];
    }
    if (ages[i] > highestAge) {
      highestAge = ages[i];
    }
  }
  cout << "Lowest age: " << lowestAge << endl;
  cout << "Highest age: " << highestAge << endl;
}