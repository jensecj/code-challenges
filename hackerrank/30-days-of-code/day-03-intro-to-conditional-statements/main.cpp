#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 == 1 || // n is odd, or
      (n % 2 == 0 && (n >= 6 && n <= 20))) // n is even and in [6,20]
    cout << "Weird";
  else if (n % 2 == 0 && // n is even, and
           ((n >= 2 && n <= 5) || n > 20)) // in [2,5], or greater than 20
    cout << "Not Weird";
}
