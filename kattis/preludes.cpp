/*
  tags: simple programming puzzle
  task: given a musical key, give its alternate name, or tells if it
  is unique
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  string node, key;

  unordered_map<string, string> map;
  map["A#"] = "Bb";
  map["Bb"] = "A#";
  map["C#"] = "Db";
  map["Db"] = "C#";
  map["D#"] = "Eb";
  map["Eb"] = "D#";
  map["F#"] = "Gb";
  map["Gb"] = "F#";
  map["G#"] = "Ab";
  map["Ab"] = "G#";

  int index = 1;
  while(cin >> node >> key) {
    cout << "Case " << index++ << ": ";
    if(map.find(node) == map.end())
      cout << "UNIQUE" << endl;
    else
      cout << map[node] << " " << key << endl;
  }
}
