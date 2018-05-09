#include <iostream>
#include <deque>

using namespace std;

class Solution {
private:
  // could also just use <stack> and <queue>, eh
  deque<char> stack;
  deque<char> queue;

public:
  void pushCharacter(char c) {
    stack.push_front(c);
  }

  char popCharacter() {
    char c = stack.front();
    stack.pop_front();

    return c;
  }

  void enqueueCharacter(char c) {
    queue.push_back(c);
  }

  char dequeueCharacter() {
    char c = queue.front();
    queue.pop_front();

    return c;
  }
};

int main() {
  // read the string s.
  string s;
  getline(cin, s);

  // create the Solution class object p.
  Solution obj;

  // push/enqueue all the characters of string s to stack.
  for (int i = 0; i < s.length(); i++) {
    obj.pushCharacter(s[i]);
    obj.enqueueCharacter(s[i]);
  }

  bool isPalindrome = true;

  // pop the top character from stack.
  // dequeue the first character from queue.
  // compare both the characters.
  for (int i = 0; i < s.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;

      break;
    }
  }

  // finally print whether string s is palindrome or not.
  if (isPalindrome) {
    cout << "The word, " << s << ", is a palindrome.";
  } else {
    cout << "The word, " << s << ", is not a palindrome.";
  }

  return 0;
}
