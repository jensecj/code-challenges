/*
  tags: hashmap
  task: given a time (e.g. 5:45), print it in words (quarter to six)
  note: this challenge is rated 'medium' on hackerrank, but it is more
  bothersome to type than to figure out
*/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  unordered_map<int,string> map;
  map[1] = "one";
  map[2] = "two";
  map[3] = "three";
  map[4] = "four";
  map[5] = "five";
  map[6] = "six";
  map[7] = "seven";
  map[8] = "eight";
  map[9] = "nine";
  map[10] = "ten";
  map[11] = "eleven";
  map[12] = "twelve";
  map[13] = "thirteen";

  map[15] = "quarter";

  map[20] = "twenty";
  map[30] = "half";
  map[40] = "forty";
  map[50] = "fifty";

  int H, M; // hours and minutes
  cin >> H >> M;

  if(M == 0) {
    cout << map[H] << " o' clock" << endl;
  }
  else if(M == 1) {
    cout << map[M] << " minute past " << map[H] << endl;
  }
  else if(M == 15 || M == 30) {
    cout << map[M] << " past " << map[H] << endl;
  }
  else if(M == 45) {
    cout << "quarter to " << map[H+1] << endl;
  }
  else if(60-M < 30) {
    if(60-M > 19) {
      int tens = ((60-M)/10)*10;
      int ones = (60-M)-tens;
      cout << map[tens] << " " << map[ones] << " minutes to " << map[H+1] << endl;
    }
    else if(60-M >= 14 && 60-M <= 19) {
      cout << map[M-10] << "teen minutes to " << map[H+1] << endl;
    }
    else {
      cout << map[60-M] << " minutes to " << map[H+1] << endl;
    }
  }
  else if (M > 14 && M < 30) {
    int tens = (M/10)*10;
    int ones = M-tens;
    cout << map[tens] << " " << map[ones] << " minutes past " << map[H] << endl;
  }
  else if(M >= 14 && M <= 19) {
    cout << map[M-10] << "teen minutes past " << map[H] << endl;
  }

}
