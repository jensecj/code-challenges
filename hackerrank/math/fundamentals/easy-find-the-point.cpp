#include <iostream>

using namespace std;

int main() {
  int T; // test cases
  cin >> T;

  while(T--) {
    int px, py, qx, qy;
    cin >> px >> py >> qx >> qy;

    cout << 2*qx-px << " " << 2*qy-py << endl;
  }
}
