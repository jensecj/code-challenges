/*
  tags: arrays, programmming puzzle
  task: given a sequence of contests, each with some luck score, and
  each being either important of not. knowing that you may at most
  lose K important contests, and that winning a contests uses the luck
  score of the contest, and losing the contests gains you the luck
  score. what is the max luck score you can get from the sequence of
  contests?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

int main() {
  int N, K; // number of contests and number of lost important
            // contests
  cin >> N >> K;
  cerr << N << ", " << K << endl;

  vector<int> importants;
  vector<int> unimportants;

  for(int i = 0; i < N; i++) {
    int luck;
    cin >> luck;
    bool important;
    cin >> important;

    // we only need to keep track of the important contests
    if(important)
      importants.push_back(luck);
    else
      unimportants.push_back(luck);
  }

  int luck = 0;

  // to maximize our luck, we just want to lose all the unimportant contests
  for(int i = 0; i < unimportants.size(); i++) {
    luck += unimportants[i];
  }

  // we can lose at most K important contests, so lets lose the ones
  // that give us the most luck
  sort(importants.begin(), importants.end(), greater<int>());

  for(int i = 0; i < K && i < importants.size(); i++) {
    luck += importants[i];
  }

  // we have to win the rest of the contests
  for(int i = K; i < importants.size(); i++) {
    luck -= importants[i];
  }

  cout << luck << endl;
}
