/*
  tags: time
  task: given two times, figure out which one is earlier
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void to_time(string time, int& hours, int& minutes) {
  int hrs = stoi(time.substr(0,2));
  int min = stoi(time.substr(3,4));
  string ampm = time.substr(5,6);

  if(ampm == "PM") {
    hrs += 12;
    if(hrs >= 24)
      hrs = 12;
  } else {
    if (hrs == 12)
      hrs = 0;
  }

  cerr << "hours: " << hrs << endl;
  cerr << "min: " << min << endl;
  cerr << ampm << endl;

  hours = hrs;
  minutes = min;
}

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    string timea, timeb;
    cin >> timea >> timeb;

    int h1, m1;
    to_time(timea, h1, m1);
    int h2, m2;
    to_time(timeb, h2, m2);

    // cerr << timea << " : " << timeb << endl;

    if(h1 < h2) cout << "First" << endl;
    else if (h2 < h1) cout << "Second" << endl;
    else if (m1 < m2) cout << "First" << endl;
    else cout << "Second" << endl;
  }
}
