/*
  tags: loop
  task: given a sequence of even or odd integers, you have the ability
  to add 1 to an obb integer, but only if you add 1 to the integer
  before or after it as well. is it possible to make the entire
  sequence into even integers? if so, print the number of additions
  you made.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; // number of people in the bread line
  cin >> N;

  vector<int> line(N);
  for (int i = 0; i < N; i++)
    cin >> line[i];

  int bread = 0;
  for (int i = 0; i < N-1; i++) {
    if(line[i] % 2 != 0) {
      line[i]++;
      line[i+1]++;
      bread += 2;
    }
  }

  if(line[N-1] % 2 == 0)
    cout << bread << endl;
  else
    cout << "NO" << endl;
}
