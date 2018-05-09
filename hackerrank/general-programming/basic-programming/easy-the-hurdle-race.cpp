/*
  tags: simple problem solving
  task: given n hurdles of height h_i,...,h_n, and a max height that
  dan can jump, and the fact that dan can drink a magic tonic which
  makes him able to jump 1 unit higher every time he drinks from it,
  figure out how many times dan has to drink to complete all the hurdles.
*/
#include <iostream>

using namespace std;

int main() {
  int n, k; // the number of hurdles, and the max height dan can jump
  cin >> n >> k;

  // we just need to find the difference from dans max jump height, to
  // the highest hurdle he has to overcome
  int max = k;
  while(n--) {
    int hurdle;
    cin >> hurdle;

    if(hurdle > max)
      max = hurdle;
  }

  cout << (max - k) << endl;
}
