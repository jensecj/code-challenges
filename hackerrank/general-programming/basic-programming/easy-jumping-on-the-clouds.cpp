/*
  tags: simple programming puzzle
  task: given n clouds, you start at cloud 0, and you want to get to
  cloud n-1, some clouds are thunder clouds, when you land on them you
  lose the game. you can either jump to cloud+1, or cloud+2, what is
  the minimum number of jumps you need to do to win the game?
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; // the number of clouds
  cin >> n;

  vector<int> clouds(n);
  for (int i = 0; i < n; i++)
    cin >> clouds[i];

  int steps = 0;
  int cloud = 0;
  do {
    if(cloud+2 < n && clouds[cloud+2] != 1)
      cloud = cloud+2;
    else
      cloud++;

    steps++;
  } while (cloud != n-1);

  cout << steps << endl;
}
