/*
  tags: stack, paren matching
  task: given a string of braces (parens, curly braces, and brackets),
  check if the string is balanced (each opening has a corresponding
  ending in a proper place)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
  int n; // number of string to check
  cin >> n;

  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;

    stack<char> stack;

    bool balanced = true;

    // for each open paren we push its counter part on the stack, and
    // then compare each close paren we find with the top of the stack
    for(auto& c : s) {
      if(c == '{') stack.push('}');
      else if (c == '(') stack.push(')');
      else if (c == '[') stack.push(']');
      else if (stack.empty() || c != stack.top()) {
        balanced = false;
      } else {
        stack.pop();
      }
    }

    // there are some parens on the stack that we have not popped yet,
    // so the string is unmatching
    if(stack.size() > 0) balanced = false;

    if(balanced) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
