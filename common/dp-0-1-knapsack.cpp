/*
  tags: dp, dynamic programming, knapsack
  description: the classical 0-1 knapsack problem. you are given a
  knapsack with some capacity W, and a list of items that each has
  some value and weight. your task is the fill your knapsack with as
  many items as you can, and achieve the biggest value in the process.
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// build a DP-table in a bottom-up manner, runtime is O(n*W), for n
// items and a knapsack with capacity W.
int DP_iterative(const vector<int> &values, const vector<int> &weights, const int knapsack) {
  int num_items = values.size();

  // DP table, values * capacity
  vector<vector<int>> table(num_items + 1, vector<int>(knapsack + 1));

  // the first row is our 'basecase', with 0 capacity we
  // cannot include any items, so the biggest value we can have,
  // trying to include any of the items is 0
  for (int i = 0; i < knapsack; i++)
    table[0][i] = 0;

  // in this approach we do not have to recurse, since we sorted the
  // dependencies in a topological order, so each requirement is met
  // when we need it in the calculation.
  for (int i = 1; i <= num_items; i++) {
    for (int w = 0; w <= knapsack; w++) {
      // if the item fits in the knapsack, we can either include it in
      // the solution, or not, we want to maximize our value for all
      // items included, we we pick the choice that gives us the
      // highest value
      if (weights[i - 1] <= w)
        table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]],
                          table[i - 1][w]);
      // otherwise we do not include this item, and the best value we
      // can get including i-1 items, and i items are the same
      else
        table[i][w] = table[i - 1][w];
    }
  }

  // return what the biggest value we can get by using num_items, and
  // a knapsack with full capacity
  return table[num_items][knapsack];
}

// without the cache, the runtime would be O(2^N), using a cache
// eliminates the repeated calculations we get because the subproblems
// overlap. the runtime with the cache is linear (we always look at a ).
int DP_recursive(const vector<int> &values, const vector<int> &weights,
                 int knapsack, int index, unordered_map<int, int> &cache) {
  // we have run out of space to store items, so we can get no more
  // extra value
  if (knapsack == 0 || index == 0)
    return 0;

  // we use this placeholder because it's convenient, we start from n,
  // and look backwards, looking at suffixes of the items all the way
  // until we have looked at all the items to be included
  int item = index - 1;

  if (cache[item])
    return cache[item];

  // if the weight of this item is more than we have capacity for, we
  // cannot include it in the solution, so try the next item
  if (weights[item] > knapsack) {
    cache[item] = DP_recursive(values, weights, knapsack, item, cache);
    return cache[item];
  }

  // otherwise we have two choices, we either include this item in the
  // best solution, or we do not
  cache[item] =
      max(values[item] + DP_recursive(values, weights, knapsack - weights[item],
                                      item, cache),
          DP_recursive(values, weights, knapsack, item, cache));

  return cache[item];
}

// helper
int DP_recursive(vector<int> &values, vector<int> &weights, int knapsack) {
  unordered_map<int, int> cache;
  return DP_recursive(values, weights, knapsack, values.size(), cache);
}

int main() {
  int knapsack = 8; // size of knapsack

  vector<int> values{1, 1, 2, 5, 4, 3, 7, 8};
  vector<int> weights{1, 2, 1, 5, 7, 1, 4, 3};

  cout << DP_iterative(values, weights, knapsack) << endl;
  cout << DP_recursive(values, weights, knapsack) << endl;
}
