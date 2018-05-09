/*
  tags: time conversion
  task: Convert an AM/PM time string to military time (24hr time)
  note: don't ever use this, use a proper time library in you
  preferred language, there are a lot of peculiarities with time, and
  rolling your own wrapper is a horrendous idea
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  string time;
  cin >> time;

  int hrs = stoi(time.substr(0,2));
  cerr << "hours: " << hrs << endl;
  int min = stoi(time.substr(3,5));
  cerr << "min: " << min << endl;
  int sec = stoi(time.substr(6,8));
  cerr << "sec: " << sec << endl;
  string ampm = time.substr(8,10);
  cerr << ampm << endl;

  if(ampm == "PM") {
    hrs += 12;
    if(hrs >= 24)
      hrs = 12;
  } else {
    if (hrs == 12)
      hrs = 0;
  }

  cout << setfill('0') << setw(2) << hrs << ":"
       << setfill('0') << setw(2) << min << ":"
       << setfill('0') << setw(2) << sec << endl;
}
