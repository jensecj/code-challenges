/*
  tags: modulo
  task: starting with 100 energy, and having the ability to jump from
  one cloud to another using 1 energy, (and you start on cloud index 0, and
  jump to cloud (index+k) % number of clouds, and every time you land
  on a thundercloud, you lose two energy, calculate the amount of
  energy left when you reach cloud 0 again)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k; // the number of clouds and the jump distance
  cin >> n >> k;

  vector<int> clouds(n);
  for (int i = 0; i < n; i++)
    cin >> clouds[i];

  int energy = 100;

  int cloud = 0;
  do {
    energy--;
    cloud = (cloud + k) % n;
    cerr << "on cloud " << cloud << endl;
    if(clouds[cloud])
      energy -= 2;
  } while(cloud != 0);

  cout << energy << endl;
}
