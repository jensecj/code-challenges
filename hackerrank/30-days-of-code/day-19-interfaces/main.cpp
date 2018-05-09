#include <iostream>

using namespace std;

class AdvancedArithmetic {
public:
  virtual int divisorSum(int n) = 0;
};

class Calculator : public AdvancedArithmetic {
public:
  Calculator() {}
  int divisorSum(int n) {
    int divisor_sum = 0;

    for(int i = 1; i <= n; i++) {
      if(n % i == 0) divisor_sum += i;
    }

    return divisor_sum;
  }
};

int main() {
  int n;
  cin >> n;
  AdvancedArithmetic *myCalculator = new Calculator();
  int sum = myCalculator->divisorSum(n);
  cout << "I implemented: AdvancedArithmetic\n" << sum;
  return 0;
}
