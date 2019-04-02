/*
  tags: sorting

  task: given n heads of a hydra, and m knights, can the knights cut off all the
  heads of the hydra? a knight can only cut off a single hydras head, and to cut
  it off, he must be at least as tall as the diameter of the head. if he manages
  to cut it off, he will be rewarded one gold piece for each cm. he is tall. the
  input is a tuple (n,m) of the number of hydra heads, and the number of
  knights, followed to n lines, with the diameter of the hydras heads, and m
  lines of the heights of the knights. what is the minimum number of gold pieces
  we need to pay the knights to cut off all the hydras heads?

  url: https://open.kattis.com/problems/loowater
*/
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

// the idea is to take each list, sort them, and then compare them from the
// start. if a knight can cut off the hydras head, then we sum his height to the
// number of gold pieces needed. if he cannot, we check if the next knight can.

int main() {
  int num_heads, num_knights;
  while (cin >> num_heads && cin >> num_knights) {
    if (num_heads == 0 && num_knights == 0) {
      return 0;
    }

    deque<int> heads(num_heads);
    for (int i = 0; i < num_heads; i++) {
      cin >> heads[i];
    }

    deque<int> knights(num_knights);
    for (int i = 0; i < num_knights; i++) {
      cin >> knights[i];
    }

    // you could short-circuit here, if heads.size() > knights.size() then its
    // not possible for the knights to save loowater, since each knight can only
    // cut off one head.

    sort(heads.begin(), heads.end());
    sort(knights.begin(), knights.end());

    int sum = 0;
    while (!heads.empty() && !knights.empty()) {
      // In order to chop off a head, a knight must be at least as tall as the
      // diameter of the head
      if (knights.front() >= heads.front()) {
        heads.pop_front();
        sum += knights.front();
        knights.pop_front();
      } else {
        // otherwise we check the next knight, we can no longer use this knight,
        // because all following dragons will be bigger than the one we just
        // looked at
        knights.pop_front();
      }
    }

    if (heads.empty()) {
      cout << sum << endl;
    } else {
      cout << "Loowater is doomed!" << endl;
    }
  }
}
