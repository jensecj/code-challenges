/*
  tags: loop, simple math
  task: given a number of days, and a scheme of how many new people
  like an advertising campaign at every new day, calculate how many
  people like the compaign after n days. (every day half of the people
  that have seen it, like it, and forward it to 3 new friends who see
  it the next day)
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n; // the number of days to check for
  cin >> n;

  int people = 5;
  int likes = 0;
  for (int i = 0; i < n; i++) {
    likes += floor(people/2);
    cerr << "people: " << people << " -> ";
    people = floor(people/2)*3;
    cerr << people << endl;
  }

  cout << likes << endl;
}
