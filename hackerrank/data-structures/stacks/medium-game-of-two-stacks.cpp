/*
  tags: stacks
  task: given two stacks of some values, and a number x, which you may
  not exceed, how many elements can you pop off the two stacks, if you
  can pick either stack to pop from at any time?
*/
#include <iostream>
#include <vector>

using namespace std;

// the gist here is that we start by adding as many elements from the
// first stack as we can, then we try adding elements from the second
// stack, removing elements we have added from the first stack if
// necessary, updating if we find a better solution, this will give us
// an optimal solution, unlike a greedy approach.
int main() {
  int g; // the number of games we play
  cin >> g;
  cerr << "games: " << g << endl;

  while(g--) {
    int n, m, x; // the number of elements in the two stacks, and the
                 // number we are not allowed to exceed
    cin >> n >> m >> x;
    // cerr << "n: " << n << ", m: " << m << ", x: " << x << endl;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
      // cerr << a[i] << " ";
    } // cerr << endl;

    for (int i = 0; i < m; i++) {
      cin >> b[i];
      // cerr << b[i] << " ";
    } // cerr << endl;

    // the total sum of our popped elements
    int sum = 0;

    // how many elements we can take from a without exceeding the limit
    int a_count = 0;
    for (int i = 0; i < n; i++) {
      if(sum + a[i] <= x) {
        sum += a[i];
        a_count++;
        // cerr << a[i] << " is fine, new sum: " << sum << endl;
      } else {
        break;
      }
    }
    // cerr << "a_count: " << a_count << endl;

    int answer = a_count;

    int b_count = 0;
    for (int i = 0; i < m; i++) {
      sum += b[i];
      b_count++;

      // cerr << "adding " << b[i] << endl;

      while(sum > x && a_count > 0) {
        sum -= a[--a_count];
        // cerr << "sum too big, removing " << a[a_count-1] << ", new sum: " << sum << endl;
      }

      if(sum <= x && a_count + b_count > answer)
        answer = a_count + b_count;

      if(a_count < 0)
        break;
    }

    // cerr << "sum: " << sum << endl;

    cout << answer << endl;
  }
}
