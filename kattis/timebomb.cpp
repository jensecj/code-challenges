/*
  tags: simple programmming puzzle, strings
  task: given an ascii counter with a number on it, print "BEER!!" if
  the number is divisible with 6, otherwise print "BOOM!!".
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
  // collapse lines and save as single string, which we can use to map
  unordered_map<string, int> map;
  map["**** ** ** ****"] = 0;
  map["  *  *  *  *  *"] = 1;
  map["***  *****  ***"] = 2;
  map["***  ****  ****"] = 3;
  map["* ** ****  *  *"] = 4;
  map["****  ***  ****"] = 5;
  map["****  **** ****"] = 6;
  map["***  *  *  *  *"] = 7;
  map["**** ***** ****"] = 8;
  map["**** ****  ****"] = 9;

  vector<string> numbers;
  string s;
  while(getline(cin, s)) {
    // get the amount of numbers in the text, each number is 3 wide +
    // 1 space (except the last number, thus the -1)
    int nums = (s.length()+1) / 4;

    // init the vector if we have not already
    if(numbers.empty())
      numbers.resize(nums);

    // grab the numbers and create the collapsed strings
    for(int i = 0; i < nums; i++) {
      numbers[i] += s.substr(i*4, 3);
    }
  }

  // concat the mapped numbers into a string, and parse that string into an int
  string snum = "";
  for(auto& s : numbers)
    snum += to_string(map[s]);

  int num = stoi(snum);

  if(num % 6 == 0)
    cout << "BEER!!" << endl;
  else
    cout << "BOOM!!" << endl;
}
