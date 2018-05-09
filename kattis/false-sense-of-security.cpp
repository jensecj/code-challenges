/*
  tags: strings
  task: given an encoded string, and the encoding/decoding scheme,
  decode the string.
  the scheme is that we turn the string into the given morse signals,
  and a string of numbers, each signaling the length of the morse code
  for a letter (because we dont use spaces between letters). we then
  reverse the string of numbers, and turn the morse code back into
  letters, and have thus decoded (or encoded) the string.
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string text;

  unordered_map<char, string> to_morse {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
 {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
 {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
 {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
 {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
 {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
 {'Y', "-.--"}, {'Z', "--.."}, {'_', "..--"}, {',', ".-.-"},
 {'.', "---."}, {'?', "----"}};

  unordered_map<string, char> from_morse;

  for(auto& kv : to_morse)
    from_morse[kv.second] = kv.first;

  while(cin >> text) {
    cerr << text << endl;
    string morse;
    string numbers;

    for(auto& c : text) {
      string morse_letter = to_morse[c];
      morse += morse_letter;
      numbers += to_string(morse_letter.length());
    }
    cerr << morse;
    cerr << numbers << endl;

    reverse(numbers.begin(), numbers.end());

    int index = 0;
    for(auto& c : numbers) {
      int len = c - '0';

      string letter = morse.substr(index, len);
      index += len;
      char decoded = from_morse[letter];
      cout << decoded;
    }
    cout << endl;
  }
}
