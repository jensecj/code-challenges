/*
  tags: dates
  task: given a day and month of the year 2009, calculate which day of
  the week it was
*/
#include <iostream>

using namespace std;

enum week_day {
  sunday = 0,
  monday = 1,
  tuesday = 2,
  wednesday = 3,
  thursday = 4,
  friday = 5,
  saturday = 6,
};

int day_of_2009_date(int month, int day) {
  static int year = 2009;
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  year -= month < 3;
  return (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int dayOfWeek(int year, int month, int day) {
  day += month < 3 ? year-- : year - 2;
  return ((((23 * month) / 9) + day + 4 + (year / 4)) - (year / 100) + (year / 400)) % 7;
}

int main() {
  int d, m;
  cin >> d >> m;

  int day = day_of_2009_date(m, d);
  // int day = dayOfWeek(2009, m, d);

  switch(day) {
  case 0: cout << "Sunday" << endl; break;
  case 1: cout << "Monday" << endl; break;
  case 2: cout << "Tuesday" << endl; break;
  case 3: cout << "Wednesday" << endl; break;
  case 4: cout << "Thursday" << endl; break;
  case 5: cout << "Friday" << endl; break;
  case 6: cout << "Saturday" << endl; break;
  }
}
