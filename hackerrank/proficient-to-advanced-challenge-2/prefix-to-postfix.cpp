/*
  tags: strings, prefix, postfix
  task: given a string which is a math expression in prefix notation,
  convert it to postfix notation (each number in the expression is a
  single digit number (e.g. +1*23 -> 123*+, or *34 -> 34*)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// check if a char is an operator
bool is_op(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

vector<string> prefixToPostfix(vector<string> prefixes) {
  vector<string> postfixes(prefixes.size());

  for (int i = 0; i < prefixes.size(); i++) {
    string prefix = prefixes[i];

    // we'll use a stack to keep track of the new expression
    stack<string> S;

    for (int i = prefix.length() - 1; i >= 0; i--) {
      // each time we encounter an op, we pop two terms, and add them
      // to the expression
      if (is_op(prefix[i])) {
        string t1, t2;
        t1 = S.top();
        S.pop();

        t2 = S.top();
        S.pop();

        // add the prefix after the two terms, converting to postfix
        t2 += prefix[i];
        S.push(t1 + t2); // push this converted part into the new
                         // expresison (this becomes a new term we can
                         // pop later i we need to handle more conversions)
      }
      // if this char is not an op, it is a term, and we just
      // push it to the stack
      else {
        S.push(string(1, prefix[i]));
      }
    }

    postfixes[i] = S.top();
    S.pop();
  }

  return postfixes;
}

int main() {
  int T; // strings to test
  cin >> T;

  vector<string> prefixes(T);

  for (int i = 0; i < T; i++)
    cin >> prefixes[i];

  vector<string> res = prefixToPostfix(prefixes);

  for(auto& s : res)
    cout << s << endl;
}
