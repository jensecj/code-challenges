/*
  tags: hashset, triplets
  task: given an array of numbers, find all the beautiful triplets. a
  triplet (a_i, a_j, a_k) is beautiful if i < j < k, and a[j] - a[i]
  == d && a[k] - a[j] == d, for some d known as the beautiful distance
  (e.g. the values of the triplets are d apart)
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  int n, d; // the amount of numbers in the sequence, and the
            // beautiful difference
  cin >> n >> d;
  cerr << "n: " << n << ", d:" << d << endl;

  // using a hashset we can keep track of the numbers we have seen
  // thus far, and we only have to enumerate the array once, so
  // runtime is O(n), and space is also O(n), since we need to keep
  // all the numbers
  unordered_set<int> nums;
  int beautiful_triplets = 0;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    // the problem spec tells us that a triplet is beautiful if i,
    // i+d, and i+2d exist, since we're inserting numbers from the
    // front, we'll look behind us to see if they exist instead
    if(nums.find(num - d) != nums.end() && nums.find(num - 2*d) != nums.end())
      beautiful_triplets++;

    nums.insert(num);
  }

  cout << beautiful_triplets << endl;
}
