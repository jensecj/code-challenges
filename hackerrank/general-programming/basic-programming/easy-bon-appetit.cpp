/*
  tags: loop
  task: figure out if brian overcharged anna for the items they ate,
  given that anna did not eat one of the items
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k; // the number of items on the bill, and the number of the
            // item that anna does not eat
  cin >> n >> k;
  cerr << "n: " << n << ", k: " << k << endl;
  vector<int> items(n);
  for (int i = 0; i < n; i++)
    cin >> items[i];

  int charged; // how much brian charged anna for her share
  cin >> charged;
  cerr << "charged: " << charged << endl;

  int real_total = 0;
  for(const int& i : items)
    real_total += i;

  real_total -= items[k]; // anna did not eat item-k
  real_total /= 2; // split the bill in two

  cerr << "real total: " << real_total << endl;

  if(real_total == charged)
    cout << "Bon Appetit" << endl;
  else
    cout << (charged - real_total) << endl;
}
