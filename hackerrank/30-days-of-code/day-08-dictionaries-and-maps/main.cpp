#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  unordered_map<string, int> phonebook;

  int n;
  cin >> n;

  while(n--) {
    string name;
    int nr;

    cin >> name >> nr;

    phonebook[name] = nr;
  }

  string query;
  while(true){
    cin >> query;

    if(query.empty())
      break;

    auto got = phonebook.find(query);
    if(got == phonebook.end())
      cout << "Not found" << endl;
    else
      cout << got->first << "=" << got->second << endl;

    query = "";
  }
}
