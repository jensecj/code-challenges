/*
  tags: LCM, GCD
  task: given two sets of numbers, find how many numbers are in
  between them, a number x is between the two sets if: all elements in
  set A are factors of x, and x is a factor of all elements in set B.
*/
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b) {
  while (b > 0) {
    int temp = b;
    b = a % b; // % is remainder
    a = temp;
  }
  return a;
}

int GCD(vector<int> input) {
  int result = input[0];
  for (int i = 1; i < input.size(); i++) {
    result = GCD(result, input[i]);
  }
  return result;
}

int LCM(int a, int b) {
  return a * (b / GCD(a, b));
}

int LCM(vector<int> input) {
  int result = input[0];
  for (int i = 1; i < input.size(); i++) {
    result = LCM(result, input[i]);
  }
  return result;
}

// by the definition of the problem, it is very straight forward that
// we need to use LCM/GCD.
int main() {
  int n, m; // the number of elements in sets A and B
  cin >> n >> m;

  vector<int> A(n), B(m);

  for (int i = 0; i < n; i++)
    cin >> A[i];
  for (int i = 0; i < m; i++)
    cin >> B[i];

  int lcm = LCM(A);
  int gcd = GCD(B);

  int count = 0;
  for(int i = lcm, j = 2; i <= gcd; i = lcm*j, j++)
    if(gcd % i == 0)
      count++;

  cout << count << endl;
}
