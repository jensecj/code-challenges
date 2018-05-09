/*
  tags: graph, arrays
  task: there are n species in the jungle, and each of them may or may
  not have a prey. each species has at most 1 direct predator (and
  thus, at most 1 prey), figure out the minimum number of groups you
  can split the species into so there are not animals in a group that
  is the others direct, or indirect prey. (there are no cycles in predators)
*/
#include <iostream>
#include <vector>

using namespace std;

// since each species has at most one direct predator, the series of
// predators turn out to be 'chains' of animals preying on each other,
// and there are no cycles, as per the problem description. so the
// problem becomes counting the biggest chain n, since for each other
// chain of size smaller than n, we can map the elements into a group
// with the first elements of n. so the length of the biggest chain
// becomes our minimum number of groups (because no animals in that
// chain can be in the same group), since there are no cycles, and
// each animal has at most one predator, runtime is O(n^2), because for
// each species, we follow the chain to count its length, and in the
// worst case, the next species we check may prey on the one we just
// checked.
int maximumGroups(vector<int> predators) {
  vector<int> colors(predators.size(), -1);

  cerr << "predators: ";
  for(auto& i : predators)
    cerr << i << " ";
  cerr << endl;

  for (int i = 0; i < predators.size(); i++) {
    // find length of this predator 'string'
    int len = 0;
    int p = predators[i];
    while(p != -1) {
      len++;
      cerr << p << " -> " << predators[p] << endl;
      p = predators[p];
    }
    cerr << "length of chain " << i << " = " << len << endl;
    colors[i] = len;
  }

  int max = 0;
  for(auto& i : colors) {
    if(i > max)
      max = i;
  }

  return max+1;
}

int main() {
  int n; // species in the jungle
  cin >> n;

  // species i has prey array[i];
  vector<int> direct_predators(n);
  for (int i = 0; i < n; i++) {
    int predator_of_i;
    cin >> predator_of_i;

    direct_predators[i] = predator_of_i;
  }

  int groups = maximumGroups(direct_predators);

  cout << groups << endl;
}
