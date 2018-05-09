/*
  tags: 2d array, spec implementation
  task: given a sequence list (2d array), and some
  weird spec, implement the spec:

  The types of queries that can be performed on your list of sequences
  are described below:

  Query: 1 x y Find the sequence, seq, at index
  ((x ^ last_ans) % N) in seq_list. Append integer y to sequence seq.

  Query: 2 x y Find the sequence, seq, at index ((x ^ last_ans) % N)
  in seq_list. Find the value of element (y % size) in seq (where size
  is the size of seq) and assign it to last_ans. Print the new value
  of last_ans on a new line */
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; // number of sequences
  int Q; // number of queries
  cin >> N >> Q;

  vector<vector<int>> seq_list(N);

  int last_ans = 0;

  for(int i = 0; i < Q; i++) {
    int type, x, y;
    cin >> type >> x >> y;

    if(type == 1)
      seq_list[(x ^ last_ans) % N].push_back(y);

    if(type == 2) {
      int idx = (x ^ last_ans) % N;
      last_ans = seq_list[idx][y % seq_list[idx].size()];
      cout << last_ans << endl;
    }
  }
}
