/*
  tags: array
  task: given an array of numbers, how many numbers can you pick from
  the array, such that all the numbers picked are at most 1 away from
  each other? (e.g. 2-1 = 1)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // the size of the array
  cin >> n;

  // the kicker here is that instead of storing the size of the array
  // n, we store the frequency of each number (the range of them is
  // only 0 < i <= 100), effectively trading space for a linear time solution
  vector<int> nums(100);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[num]++;
  }

  // runtime is O(n), since we only run through the array once, and
  // space is O(n), since we only need to store at most n numbers,
  // even if we made it possible to store 100~
  int max = 0;
  for (int i = 0; i < 100-2; i++) {
    int val = nums[i] + nums[i+1];
    if(val > max)
      max = val;
  }

  cout << max << endl;
}
