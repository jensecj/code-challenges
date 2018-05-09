/*
  tags: find biggest bucket
  task: given a stream of birds of some type (1..5), print the type of
  bird that is most common
*/
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n; // the number of birds
  cin >> n;

  map<int,int> birds;

  while(n--) {
    int bird;
    cin >> bird;
    birds[bird]++;
  }

  int max = 0;

  for(auto& b : birds) {
    if(b.second > birds[max])
      max = b.first;
  }

  cout << max << endl;
}
