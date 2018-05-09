#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

int differentTeams(string skills) {
  unordered_map<char, int> people;

  for(const char& c : skills)
    people[c]++;

  // if we have less than 5 people with different skills, there is no
  // way to form a team of 5
  if(people.size() < 5)
    return 0;

  int count = INT_MAX;
  for(auto& kv : people)
    if(kv.second < count)
      count = kv.second;

  return count;
}

int main() {
  string skills;
  cin >> skills;

  cout << differentTeams(skills) << endl;
}
