/*
  tags: input, conditionals
  task: figure out if some students are eligible or not to enter the
  ACM ICPC.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    string name;
    int start_year, start_month, start_day;
    int birth_year, birth_month, birth_day;
    int courses;
    cin >> name;
    scanf("%4d/%2d/%2d %4d/%2d/%2d %2d",
          &start_year, &start_month, &start_day, &birth_year, &birth_month, &birth_day, &courses);

    // cout << name << " " << start_year <<" " <<  start_month <<  " " << start_day << endl;
    // cout << name << " " << birth_year <<" " <<  birth_month <<  " " << birth_day << endl;

    cout << name << " ";

    if(start_year >= 2010 || birth_year >= 1991) {
      cout << "eligible" << endl;
    } else if (courses >= 41) {
      cout << "ineligible" << endl;
    } else {
      cout << "coach petitions" << endl;
    }
  }
}
