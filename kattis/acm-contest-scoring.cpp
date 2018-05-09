/*
  tags: map
  task: given some status-lines of an ACM contest for a team
  competing, output how many problems they solved, and their final
  score. the lines are on the form: <time> <problem> <answer status>,
  time is the current number of minutes into the competition, problem
  is the character describing which problem was attempted, and answer
  status is either right or wrong, depending on if it solved the
  problem. the score is awarded for each problem solved by the time it
  was handed in in minutes, minus a penalty of 20*<number of times
  attempted this problem>
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

  unordered_map<char, int> tries;

  int score = 0;
  int solved = 0;

  int minutes;
  while(cin >> minutes) {
    char problem;
    cin >> problem;
    string status;
    cin >> status;

    if(status == "right") {
      score += minutes + (20*tries[problem]);
      solved++;
    } else {
      tries[problem]++;
    }
  }

  cout << solved << " " << score << endl;
}
