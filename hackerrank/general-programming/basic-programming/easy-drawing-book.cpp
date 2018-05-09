/*
  tags: math
  task: given a book of n pages, you can either start from the front,
  or from the back, how many times do you need to flip the pages, if
  you can only flip one page at a time, to get to page p?
*/
#include <iostream>

using namespace std;

int main() {
  int n, p; // the number of pages in the book, and the page to find
  cin >> n >> p;

  // we either turn from the front, or from the back, which ever is
  // fastest
  cout << min(p/2, n/2-p/2) << endl;
}
