/*
  tags: prime, primality
  task: given p integers, determine if they are prime or not
*/
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int p;
  cin >> p;

  while(p--) {
    int n;
    cin >> n;

    // we only need to check up to sqrt(n), because if a number is
    // nonprime, it can be factored into two numbers: n = a*b, and if
    // both factors are greater than the square root of n, the number
    // would be bigger than n.
    // two is the smallest prime, and also the only even one
    if(n == 2) {
      cout << "Prime" << endl;
      continue;
    }

    // 1 and even numbers are not primes
    if(n == 1 || n % 2 == 0) {
      cout << "Not prime" << endl;
      continue;
    }

    // check if n is divisible with an odd number <= sqrt(n)
    bool prime = true;
    for(int i = 3; i <= sqrt(n); i += 2) {
      if(n % i == 0) {
        prime = false;
        break;
      }
    }

    if(prime) cout << "Prime" << endl;
    else cout << "Not prime" << endl;
  }
}
