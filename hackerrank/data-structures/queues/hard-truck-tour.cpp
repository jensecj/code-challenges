/*
  tags: queue
  task: given a ring of petrol pumps, each with some capacity, and a
  distance to the next petrol pump. you get to decide at which petrol
  pump you want to start, and you want to complete a tour around the
  entire ring of pumps (your car has an infinite capacity for petrol,
  so you can empty the stations you get to, and keep trucking along)
*/
#include <iostream>
#include <queue>

using namespace std;

struct station {
  int gas; // gas at this petrol station
  int distance; // distance to next petrol station
};

int main() {
  int N; // the number of petrol pumps in the ring
  cin >> N;

  queue<station> queue;

  for (int i = 0; i < N; i++) {
    int p, d; // the amount of petrol at this station, and the
              // distance to the next station
    station station;
    cin >> station.gas >> station.distance;
    queue.push(station);
  }

  int start = 0;
  int passed = 0;
  int gas = 0;

  // while we have not been all the way around the ring
  while (passed < N) {
    station p = queue.front();
    queue.pop();

    gas += p.gas;

    // if we have enough gas to get to the next station, do that
    if(gas >= p.distance) {
      passed++;
      gas -= p.distance;
    } else { // otherwise, try starting at the next petrol station and
             // see if that works
      start += passed + 1;
      gas = 0;
      passed = 0;
    }

    // reinsert this station into the queue, so other tries can keep
    // using it
    queue.push(p);
  }

  cout << start << endl;
}
