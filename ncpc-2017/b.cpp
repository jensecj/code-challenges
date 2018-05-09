#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class runner {
public:
  string name;
  double first;
  double other;
};

class solution {
public:
  double score;
  runner first, second, third, forth;
};

int main() {
  int num_runners;
  cin >> num_runners;

  vector<runner> runners(num_runners);
  for(int i = 0; i < num_runners; i++)
    cin >> runners[i].name >> runners[i].first >> runners[i].other;

  sort(runners.begin(), runners.end(), [] (const runner& r1, const runner& r2) {
      return r1.other < r2.other;
    });

  solution* best = NULL;
  for(int i = 0; i < num_runners; i++) {
    runner rs[4];

    rs[0] = runners[i];
    rs[1] = runners[0];
    rs[2] = runners[1];
    rs[3] = runners[2];

    if(i >= 0 && i <= 2)
      rs[i+1] = runners[3];

    solution* s = new solution();
    s->first = rs[0];
    s->second = rs[1];
    s->third = rs[2];
    s->forth = rs[3];

    s->score = s->first.first + s->second.other + s->third.other + s->forth.other;

    if(best == NULL || best->score > s->score)
      best = s;
  }

  cout << fixed << setprecision(5) << best->score << endl
       << best->first.name << endl
       << best->second.name << endl
       << best->third.name << endl
       << best->forth.name << endl;
}
