/*
  tags: bits, bitset
  task: given a set of people, each with some subset of skills (given
  in a bitstring), find the max number of skills a two-person team can
  have, also find the number of teams that can have that amount of
  skills.
*/
#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N,M; // the number of people, and topics
  cin >> N >> M;

  // 500 bits will be fine, M would be optimal
  vector<bitset<500>> people(N);

  for (int i = 0; i < N; i++) {
    string bits;
    cin >> bits;

    bitset<500> b(bits);
    people[i] = b;
  }

  int max_topics = 0;
  int max_teams = 0;
  // for all people, run through everyone else and check if their
  // skills are good complements, remember the maxes seen. runtime is
  // O(N*N*M), space is O(N*M) (actually O(N*500))
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if(i != j) {
        // find the number of set bits, which is the total amount of
        // skills of this combination of two people
        auto set_bits = (people[i] | people[j]).count();
        if(set_bits > max_topics) {
          max_topics = set_bits;
          max_teams = 1;
        } else if (set_bits == max_topics) {
          max_teams++;
        }
      }
    }
  }

  cout << max_topics << endl;
  cout << max_teams << endl;
}
