#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class Calculator {
public:
  Calculator() {}
  int power(long n, long p) {
    if(n < 0 ||p < 0)
      throw runtime_error("n and p should be non-negative");

    long ans = 1;
    for(int i = 0; i < p; i++)
      ans *= n;

    return ans;
  }
};

int main()
{
  Calculator myCalculator = Calculator();
  int T, n, p;

  cin >> T;

  while(T--){
    if(scanf("%d %d", &n, &p) == 2){
      try{
        int ans = myCalculator.power(n, p);
        cout << ans << endl;
      }
      catch(exception& e){
        cout << e.what() << endl;
      }
    }
  }
}
