/*
  tags: simple programmming puzzle
  task: given a day of a year, and two times of that day, one for
  sunrise, and one for sunset, calculate how long the sun was up
  during the day
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  string month, day, year, timea, timeb;

  while(cin >> month >> day >> year >> timea >> timeb) {
    size_t posa = timea.find(":");
    int hra = stoi(timea.substr(0, posa));
    int mina = stoi(timea.substr(posa+1, timea.length()-1));
    size_t posb = timeb.find(":");
    int hrb = stoi(timeb.substr(0, posb));
    int minb = stoi(timeb.substr(posb+1, timeb.length()-1));

    int hrs = hrb - hra;
    int mins = minb-mina;

    if(mins < 0) {
      hrs--;

      mins = 60 + mins;
    }

    cout << month << " " << day << " " << year << " " << hrs << " hours " << mins << " minutes" << endl;
  }
}
