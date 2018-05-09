/*
  tags: arrays, patterns, modulo
  task: three people have to take a test they have not studied for,
  and each of them has their own way to guess the answers on the
  multiple choice test, figure out who scores highest given their
  patterns and the actual answers to the test.
*/
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N; // number of questions on the exam
  cin >> N;

  vector<string> names {"Adrian", "Bruno", "Goran"};
  vector<vector<char>> patterns {{'A','B','C'}, {'B','A','B','C'}, {'C','C','A','A','B','B'}};
  vector<int> scores(3);

  for (int i = 0; i < N; i++) {
    char ans;
    cin >> ans;

    for (int j = 0; j < 3; j++) {
      if(ans == patterns[j][i % patterns[j].size()])
        scores[j]++;
    }
  }

  int m = *(max_element(scores.begin(), scores.end()));

  cout << m << endl;

  for (int i = 0; i < 3; i++) {
    if(scores[i] == m)
      cout << names[i] << endl;
  }
}
