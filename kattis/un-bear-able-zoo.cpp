/*
  tags: strings
  task: given a sequence of animals in a zoo, keep track of which
  kinds of animals are in the zoo, and how many of each type (e.g.
  siberian tigers, and african tigers are both tigers)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int list = 1;

  int a; // number of animals
  while(cin >> a && a != 0) {
    cin.ignore(); // get to the next line
    map<string,int> counts;
    for(int i = 0; i < a; i++) {
      string s;
      getline(cin, s);
      transform(s.begin(), s.end(), s.begin(), ::tolower);

      // get the name of the animal
      string name;
      for(int i = s.length()-1; i >= 0; i--)
        if(s[i] == ' ')
          break;
        else
          name = s[i] + name;

      counts[name]++;

      // cerr << i << " : " << name << endl;
    }

    // if we run through the map in a foreach, it prints it in
    // lexicographical order, nifty!
    cout << "List " << list++ << ":" << endl;
    for(auto& kv : counts) {
      cout << kv.first << " | " << kv.second << endl;
    }
  }
}
