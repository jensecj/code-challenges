/*
  tags: search, binary search
  task: given a dollar amount, and a list of ice creams, each with
  some price and flavour, figure out which two ice creams to buy to
  use all you money.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct IceCream {
  int index;
  int price;
};

bool ice_cream_compare(IceCream a, IceCream b) {
  // sort by price first
  if(a.price < b.price) return true;
  if(a.price > b.price) return false;

  // sort by index second
  if(a.index < b.index) return true;
  if(a.index > b.index) return false;

  return false;
}

// binary search over icecream prices
int binary_search(vector<IceCream>& icecreams, int price, int low, int high) {
  if(low > high)
    return -1;

  int mid = low + (high - low) / 2;

  if(icecreams[mid].price < price) {
    return binary_search(icecreams, price, mid+1, high);
  }

  if(icecreams[mid].price > price) {
    return binary_search(icecreams, price, low, mid-1);
  }

  return mid;
}

// helper
int binary_search(vector<IceCream>& icecreams, int price) {
  return binary_search(icecreams, price, 0, icecreams.size()-1);
}

// this is binary search pushed down upon a problem it does not quite
// fit, this is solved much simpler with a simple two-sum approach
// (in O(n) using hashmaps, instead of O(n log n) here)
int main() {
  int t; // number of trips to the ice cream parlor
  cin >> t;

  for(int i = 0; i < t; i++) {
    // cout << "-----------" << endl;
    int money;
    cin >> money;

    int n; // the number of different ice cream flavours
    cin >> n;

    // grab all the icecreams and stuff them into an array, for some
    // reason the indices start at 1
    vector<IceCream> icecreams;
    for(int j = 0; j < n; j++) {
      int price;
      cin >> price;

      IceCream ic;
      ic.index = j+1;
      ic.price = price;

      icecreams.push_back(ic);
    }

    // we're using binary serch, so we need to sort our array
    sort(icecreams.begin(), icecreams.end(), ice_cream_compare);

    // for(auto& ic : icecreams) {
    //   cout << "[" << ic.index << "] = $" << ic.price << endl;
    // }

    // this is a brute force approach to find matching price-pairs of
    // ice creams, since /money/ is <= 10^4 this will be fine
    for(int j = 1; j < money; j++) {
      vector<IceCream> ices(icecreams);
      // cout << "trying: " << j << "+" << money-j << endl;

      int a = binary_search(ices, j);
      if(a == -1) continue;

      // remove this icecream so we wont find a duplicate when we
      // search again
      IceCream ica = ices[a];
      ices.erase(ices.begin()+a);

      int b = binary_search(ices, money-j);
      if(b == -1) continue;

      IceCream icb = ices[b];

      if(ica.index > icb.index) cout << icb.index << " " << ica.index << endl;
      else cout << ica.index << " " << icb.index << endl;
      break;
    }
  }
}
