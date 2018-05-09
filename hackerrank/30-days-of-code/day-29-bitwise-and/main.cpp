#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;

  while(T--) {
    int N, K;
    cin >> N >> K;

    int max = 0;

    for(int B = 1; B <= N; B++){
      for(int A = 1; A < B; A++){
        cout << (A&B) << endl;
        if((A&B) > max && (A&B) < K){
          max = (A&B);
        }
      }
    }

    cout << max << endl;
  }
}
