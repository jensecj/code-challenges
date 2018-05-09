/*
  tags: dp, dynamic programming, substrings
  task: given a string, what is the sum of all substrings you can make?
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MOD 1000000007

int main() {
  string input;
  cin >> input;

  // convert the string into a vector of each digit
  vector<long> s(input.length());
  for(int i = 0; i < input.length(); i++)
    s[i] = input[i] - '0';

  // technically 'bottom-up' DP, since we just start at 0 and work up
  // to the highest number of digits in the number, reusing the number
  // of substrings we found from the previous calculation. the array
  // if going to contain, at index i, how many substrings can be made
  // of length i. we could use a single number to store the running
  // sum, if we needed to do it in O(1) extra space. the runtime
  // complexity of the algorithm is O(n), since we just run over each
  // number and do a computation once.
  vector<long> sum(s.size());
  sum[0] = s[0];
  long result = sum[0];
  for(int i = 1; i < s.size(); i++){
    // since the answer is output in mod 10^9+7, we can just keep
    // applying that operation, it does not change the result in the
    // end, and it keeps in inside long boundaries

    // here we calculate how many substrings can be made from a
    // substring of length i.
    sum[i] = ((i+1) * s[i]) % MOD;
    sum[i] += (10 * sum[i-1]) % MOD;

    result += sum[i];
    result = result % MOD;
  }

  cout << result << endl;
}
