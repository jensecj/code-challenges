/*
  tags: dp, dynamic programming
  task: you have to drive around the world in a straight line, your
  track has some capacity for gas C, and each city you meet on your
  way has a gas pump with some amount of gas, you start at one of
  these cities. given a configuration of gas at pumps, and capacity in
  your truck, and the distance between each city you meet (you drive
  1km per litre of gas, etc.) calculate how many different cities you
  can start in, and make it around the world!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedy(vector<long>& gas_at_city, vector<long> distance_to_next, int N, int C) {
  long long m = *max_element(distance_to_next.begin(), distance_to_next.end());

  // if theres a city where it takes more gas to get to, than we can
  // have in the car, we cannot get around the world
  if(m > C) {
    cerr << "it is impossible to get around the world!" << endl;
    return 0;
  }

  long long total_distance_to_get_around_the_world = 0;
  long long total_gas_of_all_cities = 0;
  for(int i = 0; i < N; i++) {
    if(gas_at_city[i] > C)
      total_gas_of_all_cities += C;
    else
      total_gas_of_all_cities += gas_at_city[i];

    total_distance_to_get_around_the_world += distance_to_next[i];
  }

  // pretty self explanatory
  if(total_distance_to_get_around_the_world > total_gas_of_all_cities) {
    cerr << "it is impossible to get around the world!" << endl;
    return 0;
  }

  int count = 0;
  int start = 0;
  int successful_index = -1;

  while (start < N) {
    long remaining_gas = 0;
    bool got_around_the_world = true;

    // try different start indices until we have tried all
    // possibilities, we do not have to try all indices because some
    // 'paths' can be excluded when we find it impossible to pass
    for (int i = start; i <= N + successful_index; i++) {
      // how much gas do we have now
      if(remaining_gas + gas_at_city[i % N] < C)
        remaining_gas += gas_at_city[i % N];
      else
        remaining_gas = C;

      // it costs gas to get to the next city
      remaining_gas -= distance_to_next[i % N];

      if (remaining_gas < 0) {
        if (i > N) {
          // we got all around the world!
          break;
        } else {
          // we did not get around the world, try a new tour starting
          // froused_gas the index after the one wa failed from
          start = i + 1;
          got_around_the_world = false;
          break;
        }
      }
    }

    if (got_around_the_world) {
      start++;
      count++;
      if (successful_index == -1) {
        successful_index = start;
      }
    }
  }

  return count;
}

int dp(const vector<long long>& gas_from_city, const vector<long long>& distance_to_city, long long C){
  vector<long long> d(gas_from_city.size());

  int count = 0;
  long long used_gas = 0;

  // in the first pass we'll check if there are any cities where it's
  // impossible to get to, we also keep a running sum of how much gas
  // we have used to get to the different cities.
  for (int i = gas_from_city.size() - 1; i >= 0; i--){
    // count used gas
    used_gas += distance_to_city[i];

    // if we've used more gas than we have capacity for, we cannot get here
    if (used_gas > C)
      return 0;

    if (used_gas > gas_from_city[i]) {
      // discount the gas we get from the city
      used_gas -= gas_from_city[i];
      // remember how much gas we used to get here
      d[i] = used_gas;
    }
    else{
      // if we get more gas from the city than it has taken to get
      // here, it has effectively taken 0 gas (for future reference)
      d[i] = used_gas = 0;
      // count this as a possible solution
      count++;
    }
  }

  // second pass
  for (int i = gas_from_city.size() - 1; i >= 0; i--){
    // count used gas
    used_gas += distance_to_city[i];

    // if we've used more gas than we have capacity for, we cannot get here
    if (used_gas > C)
      return 0;

    long long gas_used_to_get_here;
    if (used_gas > gas_from_city[i])
      gas_used_to_get_here = used_gas - gas_from_city[i];
    else
      gas_used_to_get_here = 0;

    if (gas_used_to_get_here == d[i])
      break;

    if (!d[i])
      count--;

    d[i] = used_gas = gas_used_to_get_here;
  }

  return count;
}

int main() {
  int N; // number of cities
  cin >> N;

  long long C; // capacity of truck
  cin >> C;

  vector<long long> gas_at_city(N);
  for(int i = 0; i < N; i++)
    cin >> gas_at_city[i];

  vector<long long> distance_to_next(N);
  for(int i = 0; i < N; i++)
    cin >> distance_to_next[i];

  cout << dp(gas_at_city, distance_to_next, C) << endl;
}
