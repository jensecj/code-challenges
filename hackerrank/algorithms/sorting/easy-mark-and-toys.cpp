/*
  tags: sorting
  task: mark wants to buy toys for his kid, given how much money has
  to spend on toys, and the different prices for n different toys, how
  many toys can mark buy?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int N, K; // number of toys, and cash mark has to buy toys for
  cin >> N >> K;

  vector<int> toys(N);
  for(int i = 0; i < N; i++)
    cin >> toys[i];

  sort(toys.begin(), toys.end());

  int sum = 0;
  int toy_count = 0;
  for(int i = 0; i < N; i++) {
    if(sum + toys[i] > K)
      break;

    sum += toys[i];
    toy_count++;
  }

  cout << toy_count << endl;
}
