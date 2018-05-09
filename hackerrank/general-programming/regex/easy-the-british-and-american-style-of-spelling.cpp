/*
  tags: regex
  task: find occurrences of american and british spellings in a text
*/
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
  int N; // the number of lines of input
  cin >> N;
  cerr << "lines in input: " << N << endl;

  string input = "";
  for (int i = 0; i < N; i++) {
    string in;
    getline(cin, in);
    input += " " + in;
  }

  cerr << "input: " << input << endl;

  int T; // number of testcases
  cin >> T;
  cerr << "testcases: " << T << endl;

  while(T--) {
    string american_spelling;
    cin >> american_spelling;

    string root = american_spelling.substr(0, american_spelling.size()-2);

    regex e(root + "[sz]e");

    smatch m;
    int matches = 0;
    while(regex_search(input, m, e)) {
      matches++;
      input = m.suffix().str();
      // cerr << "suffix: " << input << endl;
    }

    cout << matches << endl;
  }
}
