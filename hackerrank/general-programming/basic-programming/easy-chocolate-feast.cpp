/*
  tags: math puzzle
  task: given a dollar amount, the price of chocolates, and some value
  m, for which we know that m chocolate wrappers can be traded back in
  for a new piece of chocolate, figure out how many pieces of
  chocolate you can get for n dollars!
*/
#include <iostream>

using namespace std;

int main() {
  int t; // number of trips to the chocolate store
  cin >> t;
  cerr << "trips: " << t << endl;

  while(t--) {
    int n,c,m; // n - dollars to buy chocolates with, c - cost of each
               // chocolate, m - the number of wrappers to turn in for
               // a free piece of chocolate
    cin >> n >> c >> m;
    cerr << "n: " << n << ", c: " << c << ", m: " << m << endl;

    int choco = n / c;
    int wrappers = choco;

    while(wrappers >= m) {
      wrappers -= m;
      wrappers++;
      choco++;
    }

    cout << choco << endl;
  }
}
