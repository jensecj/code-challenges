#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double mealCost;
  int tipPercent;
  int taxPercent;

  cin >> mealCost >> tipPercent >> taxPercent;

  float tip = mealCost * (tipPercent/100.0);
  float tax = mealCost * (taxPercent/100.0);
  float totalCost = mealCost + tip + tax;

  cout << "The total meal cost is " << round(totalCost) << " dollars.";
}
