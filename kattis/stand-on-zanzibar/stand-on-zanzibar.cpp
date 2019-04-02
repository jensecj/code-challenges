/*
  tags: arrays
  task: turtles on zanzibar do not die, and every year, every turtle
  has atmost one child. given we started with 1 turtle on zanzibar,
  and an array of the number of turtles on zanzibar every year. figure
  out how many turtles were imported to zanzibar.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T; // testcases
  cin >> T;

  while(T--) {
    vector<int> nums(1);

    int num;
    cin >> num;

    while(num != 0) {
      nums.push_back(num);
      cin >> num;
    }

    int imports = 0;
    for (int i = 1; i < nums.size(); i++) {
      if(nums[i] > 2*nums[i-1]) {
        imports += nums[i] - (2*nums[i-1]);
      }
    }

    cout << imports-1 << endl;
  }
}
