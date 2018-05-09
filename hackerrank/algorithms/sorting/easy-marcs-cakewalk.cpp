/*
  tags: math
  task: marc wants to eat n cupcakes, each cupcake has c_i,...,c_n
  calories, and mark has to walk off the calories after he has eaten
  them all, the miles marc has to walk for a given cupcake is given by
  (2^j)*c, where c is the calories for that cupcake, and j is the
  number of cupcakes he has already eaten. print the minimum number of
  miles marc will have to walk after having eaten all the cupcakes.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n; //the number of cupcakes
  cin >> n;

  vector<int> cupcakes(n);
  for (int i = 0; i < n; i++)
    cin >> cupcakes[i];

  int cupcakes_eaten = 0;
  long miles_to_walk = 0;

  // the trick here is to sort from highest to lowest, since high
  // numbers with higher exponents are bad. (we want the minimum)
  sort(cupcakes.begin(), cupcakes.end(), greater<int>());

  for(const int& i : cupcakes) {
    miles_to_walk += pow(2, cupcakes_eaten) * i;
    cupcakes_eaten++;
  }

  cout << miles_to_walk << endl;
}
