/*
  tags: loop, round
  task: given an array of numbers, if a number is above 38, and is
  less than 3 from its nearest multiple of 5 (upwards), round the
  number up to that multiple of 5
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // the number of grades
  cin >> n;

  vector<int> grades(n);

  for (int i = 0; i < n; i++)
    cin >> grades[i];

  for (int i = 0; i < n; i++) {
    if(grades[i] < 38) continue;

    for (int j = 0; j < 3; j++) {
      if((grades[i]+j) % 5 == 0) {
        grades[i] += j;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << grades[i] << endl;
}
