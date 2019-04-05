/*
  tags: hashmap

  task: translate an input string to l337.

  url: https://open.kattis.com/problems/anewalphabet
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string input;
  getline(cin, input);

  transform(input.begin(), input.end(), input.begin(), ::tolower);

  map<char, string> h{
      {'a', "@"},       {'b', "8"},      {'c', "("},      {'d', "|)"},
      {'e', "3"},       {'f', "#"},      {'g', "6"},      {'h', "[-]"},
      {'i', "|"},       {'j', "_|"},     {'k', "|<"},     {'l', "1"},
      {'m', "[]\\/[]"}, {'n', "[]\\[]"}, {'o', "0"},      {'p', "|D"},
      {'q', "(,)"},     {'r', "|Z"},     {'s', "$"},      {'t', "']['"},
      {'u', "|_|"},     {'v', "\\/"},    {'w', "\\/\\/"}, {'x', "}{"},
      {'y', "`/"},      {'z', "2"}};

  ostringstream output;
  for (auto &c : input) {
    if (h.find(c) != h.end()) {
      output << h[c];
    } else {
      output << c;
    }
  }

  cout << output.str() << endl;
}
