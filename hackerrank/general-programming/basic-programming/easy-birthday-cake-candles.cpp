/*
  tags: loop
  task: given a stream of numbers, print how many times the largest
  one has occured
*/
#include <iostream>

using namespace std;

int main() {
  int n; // the number of candles on Colleens cake
  cin >> n;

  int max_height = 0;
  int candles = 0;

  while(n--) {
    int candle;
    cin >> candle;
    if(candle > max_height) {
      candles = 1;
      max_height = candle;
    } else if (candle == max_height)
      candles++;
  }

  cout << candles << endl;

}
