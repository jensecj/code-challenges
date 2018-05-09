#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool ends_with(string s, string ending) {
  if (s.length() >= ending.length()) {
    return (0 == s.compare(s.length() - ending.length(), ending.length(), ending));
  } else {
    return false;
  }
}

int main(){
  vector<string> names;

  int n = 0;
  cin >> n;

  while(n--) {
    string name;
    string email;

    cin >> name >> email;

    transform(email.begin(), email.end(), email.begin(), ::tolower);
    
    if(ends_with(email, "@gmail.com")) {
      names.push_back(name);
    }
  }

  sort(names.begin(), names.end());

  for(auto &n : names) {
    cout << n << endl;
  }
}
