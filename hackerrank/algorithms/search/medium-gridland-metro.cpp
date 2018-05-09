/*
  tags: intervals, search, overlap
  task: given some intervals of train tracks (where they begin and
  end) on rows in a matrix, calculate how many cells in the matrix
  do not contain any train tracks.
*/
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

struct interval {
  long start = 0, end = 0;
};

// merges all overlapping intervals, by first sorting the array of
// intervals by their starting time, then we start with the first
// interval of the array, and push it to a stack and start comparing
// against the rest. if an element does not overlap with the top
// element of the stack, then we push it to the stack, as it is a
// distinct interval. it it does overlap, then we expand the top
// element of the stack to include the end of the element we are
// comparing against, if it is further away than tops end.n
vector<interval> merge_intervals(vector<interval>& intervals) {
  sort(intervals.begin(), intervals.end(),
       [](const auto& lhs, const auto& rhs) { return lhs.start < rhs.start;});

  for(int i = 0; i < intervals.size(); i++) {
    cerr << "[" <<  intervals[i].start << "," << intervals[i].end << "] ";
  } cerr << endl;

  stack<interval> s;
  s.push(intervals[0]);

  for(int i = 1; i < intervals.size(); i++) {
    interval top = s.top();
    cerr << "top interval " << top.start << "," << top.end << endl;
    cerr << "testing interval " << intervals[i].start << "," << intervals[i].end << endl;

    // if the end of this element is less that the start of the next,
    // then the two intervals are disjoint
    if(top.end < intervals[i].start) {
      s.push(intervals[i]);
      cerr << " new interval: " << intervals[i].start << "," << intervals[i].end << endl;
    }
    // otherwise there is an overlap, but we only need to update the
    // interval if the one overlapping makes this a longer interval
    else if (top.end < intervals[i].end) {
      cerr << " expanding interval: " << top.start << "," << top.end << " -> " << top.start << "," << intervals[i].end << endl;
      top.end = intervals[i].end;
      s.pop();
      s.push(top);
    }
    cerr << endl;
  }

  vector<interval> res;
  while(!s.empty()) {
    res.push_back(s.top());
    s.pop();
  }

  return res;
}

int main() {
  long n,m,k; // number of rows, columns, and train tracks
  cin >> n >> m >> k;

  long total = n*m;
  cerr << total << endl;

  unordered_map<long, vector<interval>> intervals;

  for(int i = 1; i <= k; i++) {
    long r,c1,c2; // row of track, and start and end points
    cin >> r >> c1 >> c2;
    // cerr << r << " = [" << c1 << "," << c2 << "]" << " = " << c2 - c1 + 1 << endl;

    intervals[r].push_back({c1, c2});
  }

  // for each row in the matrix, we merge the intervals, and
  // accumulate how many cells are occupied by train tracks
  long tracks = 0;
  for(auto& kv : intervals) {
    vector<interval> inter = kv.second;
    cerr << kv.first << ": ";
    inter = merge_intervals(inter);

    for(int i = 0; i < inter.size(); i++) {
      tracks += inter[i].end - inter[i].start + 1;
    }
  }
  cerr << endl;

  cout << total - tracks << endl;
}
