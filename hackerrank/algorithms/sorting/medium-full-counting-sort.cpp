/*
  tags: sorting, counting sort, stable sort
  task: given a sequence of (int, string) pairs, you have to sort the
  sequence of numbers, but print the strings of the associated numbers
  in their original position, and if a string is from the first half
  of the original sequence, print '-' in its stead.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  vector<string> words(n);
  unordered_map<int, int> counts;

  int max_num = 0;

  for(int half = n/2, i = 0; i < n; i++) {
    cin >> nums[i] >> words[i];

    if(i < half)
      words[i] = "-";

    counts[nums[i]]++;

    if(nums[i] > max_num)
      max_num = nums[i];
  }

  for(int i = 1; i <= max_num; i++)
    counts[i] += counts[i - 1];

  vector<string> output(n);
  for(int i = n - 1; i >= 0; i--) {
    counts[nums[i]]--;
    int position = counts[nums[i]];
    output[position] = words[i];
  }

  for(auto i = 0; i < n; i++)
    cout << output[i] << " ";
  cout << endl;
}
