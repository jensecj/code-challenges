/*
  tags: simple programming puzzla
  task: given a threshold of students we need before starting a class,
  and an array of students arrival times, determine whether or not
  class is calceled. class is calceled if fewer than K students have
  arrived when class should start.
*/
#include <iostream>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    int N, K; // number of students in class, and cancelation
              // threshold
    cin >> N >> K;

    int late_students = 0;
    for (int i = 0; i < N; i++) {
      int arrival_time;
      cin >> arrival_time;

      if(arrival_time > 0)
        late_students++;
    }

    if(N - late_students < K)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
