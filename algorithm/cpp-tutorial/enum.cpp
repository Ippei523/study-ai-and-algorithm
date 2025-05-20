#include <iostream>
using namespace std;

// enum Level
// {
//   LOW = 25,
//   MEDIUM = 50,
//   HIGH = 75
// };

// int main()
// {
//   Level myLevel = MEDIUM;

//   cout << "The value of myLevel is: " << myLevel << endl;

//   return 0;
// }

enum Rank
{
  FIRST = 1,
  SECOND,
  THIRD
};

int main()
{
  Rank myRank = SECOND;

  switch (myRank)
  {
  case FIRST:
    cout << "First rank" << endl;
    break;
  case SECOND:
    cout << "Second rank" << endl;
    break;
  case THIRD:
    cout << "Third rank" << endl;
    break;
  default:
    cout << "Unknown rank" << endl;
  }
  cout << "The value of myRank is: " << myRank << endl;

  return 0;
}