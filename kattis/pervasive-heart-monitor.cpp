/*
  tags: strings
  task: you have a gym, and people who enter can either swipe their
  member cards as they enter, or as they leave, while they workout,
  every minute their pulse is registered. as a result you have records
  on the form <name> <a> <b> ... <z>, or <a> <b> ... <z> <name> (the
  name is either in front, or behind the pulse data). given this data,
  calculate each members average pulse, and print it, then print their
  name.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
  string s;

  while(getline(cin, s)){
    stringstream ss;
    ss << s;

    double sum = 0;
    int count = 0;

    string name, w;
    while(ss >> w){
      if(w[0] >= '0' && w[0] <= '9'){
        sum += stod(w);
        count++;
      } else {
        name += w + " ";
      }
    }

    sum /= count;
    name.pop_back();

    cout << setprecision(6) << sum << " " << name << endl;
  }
}

void main2() {
  string s;
  while(getline(cin, s)) {
    vector<double> times;
    string name;

    size_t pos = 0;
    while ((pos = s.find(" ")) != string::npos) {
      string part = s.substr(0, pos);

      if((part[0] >= 48 && part[0] <= 57) || s[0] == '.')
        times.push_back(stod(part));
      else
        name += part + " ";

      s.erase(0, pos + 1);
    }

    if((s[0] >= 48 && s[0] <= 57) || s[0] == '.')
      times.push_back(stod(s));
    else
      name += s + " ";

    // for(auto& a : times) {
    // cerr << a << " ";
    // }

    name = name.substr(0, name.length()-1);

    cerr << fixed
         << setprecision(6)
         << accumulate(times.begin(), times.end(), 0.0) / times.size()
         << " " << name << endl;
  }
}
