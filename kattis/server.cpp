/*
  tags: simple programmming puzzle
  task: given n tasks which each take some amount of time, and a
  deadline, how many of the tasks can you complete before the
  deadline? you have to complete them in order or arrival.
*/
#include <iostream>

using namespace std;

int main() {
  int n, T; // number of requests, and the deadline
  cin >> n >> T;

  int tasks_completed = 0;
  int time = 0;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;

    if(time + t > T)
      break;

    time += t;
    tasks_completed++;
  }

  cout << tasks_completed << endl;
}
