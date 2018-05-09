/*
  tags: loop
  task: given a number, count from 1 to that number, and for each time
  counting, print the number you are at, and 'Abracadabra' on a
  newline (e.g. "# Abracadabra")
 */
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cout << i << " Abracadabra" << endl;
  }
}
