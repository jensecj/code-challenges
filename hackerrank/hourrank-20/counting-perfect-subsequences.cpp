#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <unordered_map>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

int sub[10];

bool is_perfect(string s) {
  unordered_map<char,int> map;
  for(auto& c : s)
    map[c]++;

  return map['a'] == map['b'] && map['c'] == map['d'];
}

// void subsequences(char* prefix, int prefixLength, const char* suffix, vector<string>& res) {
//   if (prefixLength >= 2)
//     res.push_back(string(prefix, prefixLength));
//   // printf("%s\n", prefix);

//   for (size_t i=0; i < strlen(suffix); ++i) {
//     prefix[prefixLength] = suffix[i];
//     prefix[prefixLength + 1] = '\0';
//     subsequences(prefix, prefixLength + 1, suffix + i + 1, res);
//   }
// }
void subsequences_s(const std::string& prefix, const std::string& suffix, vector<string>& res) {
  if (prefix.length() >= 2)
    res.push_back(prefix);
  // std::cout << prefix << std::endl;

  for (size_t i=0; i < suffix.length(); ++i)
    subsequences_s(prefix + suffix[i], suffix.substr(i + 1), res);
}

int main() {
  int q; // the number of queries
  cin >> q;

  while(q--) {
    string query;
    cin >> query;

    unordered_map<char, int> map;
    for(auto& c : query)
      map[c]++;

    // char *prefix = (char*) malloc(strlen(query.c_str() + 1));
    long subs = 0;

    vector<string> powerset;
    // subsequences(prefix, 0, query.c_str(), powerset);
    subsequences_s("", query, powerset);
    for(auto& s : powerset) {
      // cerr << s << endl;
      if(is_perfect(s))
        subs++;
    }

    long m = pow(10,9) + 7;
    cout << subs % m << endl;
  }
}
