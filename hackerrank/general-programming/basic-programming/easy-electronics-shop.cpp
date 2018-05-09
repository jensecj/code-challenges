/*
  tags: loops, arrays
  task: given two lists of items, each with a different price, and a
  dollar amount, find the two items from the lists that you can buy to
  spend the max amount of dollars in you budget
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int s, n, m; // amount of dollars monica has to spend, the number of
               // keyboards, and the number of usb keys
  cin >> s >> n >> m;

  vector<int> keyboards(n);
  vector<int> usbkeys(m);

  for (int i = 0; i < n; i++)
    cin >> keyboards[i];
  for (int i = 0; i < m; i++)
    cin >> usbkeys[i];

  // the numbers are low enough that we can easily brute force the problem
  int max = -1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(keyboards[i] + usbkeys[j] <= s && keyboards[i] + usbkeys[j] > max)
        max = keyboards[i] + usbkeys[j];
    }
  }

  cout << max << endl;
}
