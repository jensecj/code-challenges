/*
  tags: stacks, making stacks equal height
  task: given 3 stacks of numbers (heights of cylinders, also input is
  in reverse). figure out how high the three stacks can be, if they
  all need to be the same height. (think of the numbers in the stacks,
  as the heights of some blocks, which are stacked on top of each other)
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

  int n1, n2, n3; // the number of cylinders in stacks 1, 2, and 3
  cin >> n1 >> n2 >> n3;

  // the input gives us the numbers for the stacks in reverse (the
  // first input is the top cylinder of the stack), so for each stack
  // we build an array of the cylinders heights. we also stack the
  // heights because that is all we really need.

  vector<int> c1, c2, c3;

  for (int i = 0; i < n1; i++) {
    int in;
    cin >> in;
    c1.push_back(in);
  }
  for (int i = 0; i < n2; i++) {
    int in;
    cin >> in;
    c2.push_back(in);
  }
  for (int i = 0; i < n3; i++) {
    int in;
    cin >> in;
    c3.push_back(in);
  }

  // cout << "vectors:" << endl;
  // for(const int& i : c1)
  //   cout << i << " ";
  // cout << endl;
  // for(const int& i : c2)
  //   cout << i << " ";
  // cout << endl;
  // for(const int& i : c3)
  //   cout << i << " ";
  // cout << endl;

  stack<int> s1, s2, s3;

  for(int i = n1-1; i >= 0; i--) {
    if(s1.empty())
      s1.push(c1[i]);
    else
      s1.push(c1[i] + s1.top());
  }
  for(int i = n2-1; i >= 0; i--) {
    if(s2.empty())
      s2.push(c2[i]);
    else
      s2.push(c2[i] + s2.top());
  }
  for(int i = n3-1; i >= 0; i--) {
    if(s3.empty())
      s3.push(c3[i]);
    else
      s3.push(c3[i] + s3.top());
  }

  // cout << "stacks: " << endl;
  // while(!s1.empty()) {
  //   cout << s1.top() << " ";
  //   s1.pop();
  // }
  // cout << endl;
  // while(!s2.empty()) {
  //   cout << s2.top() << " ";
  //   s2.pop();
  // }
  // cout << endl;
  // while(!s3.empty()) {
  //   cout << s3.top() << " ";
  //   s3.pop();
  // }
  // cout << endl;

  int h1, h2, h3;
  h1 = s1.empty() ? 0 : s1.top();
  h2 = s2.empty() ? 0 : s2.top();
  h3 = s3.empty() ? 0 : s3.top();

  // while the heights of the stacks are different, figure out which
  // cylinders to remove
  while(h1 != h2 || h2 != h3) {
    if(h1 >= h2 && h1 >= h3) {
      s1.pop();
      h1 = s1.empty() ? 0 : s1.top();
    } else if (h2 >= h1 && h2 >= h3) {
      s2.pop();
      h2 = s2.empty() ? 0 : s2.top();
    } else {
      s3.pop();
      h3 = s3.empty() ? 0 : s3.top();
    }
  }

  // they're all the same here, so just print whichever
  cout << h1 << endl;
}
