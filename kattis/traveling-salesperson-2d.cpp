/*
  tags:
  task:
*/
#include <iostream>
#include <vector>

using namespace std;

struct point {
  double x;
  double y;
};

vector<point> greedy_tour(vector<point>& points) {
  vector<point> tour;
  vector<point> used;

}

int main() {
  int N; // number of points in problem
  cin >> N;

  vector<point> points(N);

  for(int i = 0; i < N; i++) {
    point p;
    cin >> p.x >> p.y;
    points[i] = p;
  }

  for(auto& p : points)
    cout << p.x << ", " << p.y << endl;
}
