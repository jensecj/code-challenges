/*
  tags: min heap
  task: you are the owner of a pizza shop, but instead of making
  orders based on which customer arrives first, you make orders so the
  average waiting time of all customers in your shop is minimized.
  given n events, where a customer arrives at some time t1, and orders
  a pizza which takes time t2 to make, figure out the minimum average
  waiting time for the customers.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct Customer {
  long arrival_time;
  long baking_time;
};

struct CompareArrival {
  bool operator() (const Customer& a, const Customer& b) {
    return a.arrival_time > b.arrival_time;
  }
};
struct CompareBaking {
  bool operator() (const Customer& a, const Customer& b) {
    return a.baking_time > b.baking_time;
  }
};

int main() {
  int N; // the number of customers
  cin >> N;

  priority_queue<Customer, vector<Customer>, CompareArrival> all_customers;
  priority_queue<Customer, vector<Customer>, CompareBaking> waiting_list;

  // apparently the customers do not arrive in an ordered way, so we
  // need to store all arrivals first, then loop through them based on
  // the time they arrive...

  long max_time = 0;
  long customers_to_go = N;
  while(customers_to_go--) {
    Customer c;
    cin >> c.arrival_time >> c.baking_time;

    cerr << "new customer: " << c.arrival_time << "," << c.baking_time << endl;

    // keep track of the latest customer to arrive
    if(c.arrival_time > max_time)
      max_time = c.arrival_time;

    all_customers.push(c);
  }

  cerr << "max time: " << max_time << endl;

  long time_to_process_orders = 0;

  long time = 0;
  while(!all_customers.empty() || !waiting_list.empty()) {
    // see if someone arrived at time i
    while(!all_customers.empty() && all_customers.top().arrival_time <= time) {
      cerr << "found order at time " << time << endl;
      waiting_list.push(all_customers.top());
      all_customers.pop();
    }

    // if there are customers in the waiting list (which is sorted by
    // fastest baking time), then pick an order and make it
    if(!waiting_list.empty()) {
      Customer c = waiting_list.top();
      cerr << "processing order from customer "
           << c.arrival_time
           << ", will take "
           << c.baking_time << endl;

      // this order will be done at time + baking time, to get the
      // time the customer waited, subtract the time he arrived
      time_to_process_orders += time + c.baking_time - c.arrival_time;
      time += c.baking_time;
      waiting_list.pop();
    } else {
      time++;
    }
  }
  cerr << time_to_process_orders << "/" << N << endl;
  cout << (long)(time_to_process_orders / N) << endl;
}
