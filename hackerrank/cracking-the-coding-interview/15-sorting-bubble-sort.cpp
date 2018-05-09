/*
  tags: sorting, bubble sort
  task: count the number of index swaps in bubblesort
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for(int a_i = 0;a_i < n;a_i++){
    cin >> a[a_i];
  }

  int totalSwaps = 0;

  for (int i = 0; i < n; i++) {
    // Track number of elements swapped during a single array traversal
    int numberOfSwaps = 0;

    for (int j = 0; j < n - 1; j++) {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j + 1]) {
        int tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
        //swap(a[j], a[j + 1]);
        numberOfSwaps++;
      }
    }

    // If no elements were swapped during a traversal, array is sorted
    if (numberOfSwaps == 0) {
      break;
    }
    totalSwaps += numberOfSwaps;
  }

  cout << "Array is sorted in " << totalSwaps << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[a.size()-1] << endl;

}
