/*
  tags: calendars
  task: given a year, print the date of the day-of-the-programmer,
  using the russian calendar year, and taking note of leap days and
  that the russian calendar changed in 1918
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int year;
  cin >> year;

  if(year == 1918){
    cout << "26.09." << year << endl; // 1918 was a weird year
  } else if((year % 4 == 0 && year % 100 != 0)
            || year % 400 == 0
            || year == 1700
            || year == 1800
            || year == 1900) {
    cout <<  "12.09." << year << endl; // ordinary year
  } else {
    cout << "13.09." << year << endl; // leap year
  }
}
