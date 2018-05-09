/*
  tags: programming puzzle
  task: given a book of n chapters, each with t_i problems (and where
  each chapter starts on a new page, and no page has problems from
  more than one chapter at once), find the number of 'special
  problems', a problem is special if it has the same index as the page
  it is on.
*/
#include <iostream>

using namespace std;

int main() {
  int n, k; // number of chapters, and max number of problems on a page
  cin >> n >> k;

  int t;
  cin >> t;

  int special_chapters = 0;
  int chap = 1;
  int page = 1;
  int prob = 1;
  // loop through all the chapters
  while (chap <= n){
    int cap;
    // the max number of problems that can be on this page
    if(prob + k - 1 < t)
      cap = prob + k - 1;
    else
      cap = t; // set to t if this is the last page

    // record the problem if it is special
    if (prob <= page && page <= cap)
      special_chapters++;

    // go to next page
    page++;
    prob += k;

    // start the next chapter if we need to
    if (prob > t){
      prob = 1;
      chap++;

      cin >> t;
    }
  }

  cout << special_chapters << endl;
}
