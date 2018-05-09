/*
  tags: simple
  task: given some number of participants, and some hotels, with a
  price-per-person, and some availability of rooms, find the minimum
  price you have to pay for everyone to stay at the same hotel, if
  there is one where there is enough room, and if the price is within
  some budget B.
*/
#include <iostream>
#include <climits>

using namespace std;

int main() {
  int participants,budget,num_hotels,num_weeks;

  while(cin >> participants >> budget >> num_hotels >> num_weeks) {
    int min = INT_MAX;

    // cerr << "participants: " << participants << ", budget: " << budget << ", hotels: " << num_weeks << ", weeks: " << num_weeks << endl;
    for(int i = 0; i < num_hotels; i++) {
      int price;
      cin >> price;

      // cerr << "hotel " << i << " : $" << price << endl;

      for(int j = 0; j < num_weeks; j++) {
        int room;
        cin >> room;

        // cerr << " week " << j << ": " << room << endl;

        if(room >= participants)
          if(price * participants < min && price * participants <= budget)
            min = price * participants;
      }
    }
    if (min == INT_MAX)
      cout << "stay home" << endl;
    else
      cout << min << endl;
  }
}
