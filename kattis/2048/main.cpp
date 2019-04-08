/*
  tags:

  task: given a state of the 2014 puzzle, and a move, print the resulting state.

  url: https://open.kattis.com/problems/2048
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using line = vector<int>;
using matrix = vector<vector<int>>;

class board {
private:
public:
  matrix state{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  board() {}
  board(matrix m) { state = m; }

  line row(int n) { return state[n]; }

  line col(int n) {
    return vector<int>{state[0][n], state[1][n], state[2][n], state[3][n]};
  }

  void set_row(int i, line r) { state[i] = r; }

  void set_col(int i, line r) {
    state[0][i] = r[0];
    state[1][i] = r[1];
    state[2][i] = r[2];
    state[3][i] = r[3];
  }
};

// notice that we will only ever have to merge a line in one direction, once we
// can do that, we can merge all lines in the puzzle by rotating the puzzle, and
// then merging.

line move_row_left(line r) {
  // move -> merge -> move
  for (int i = 0; i < 3; i++) {
    if (r[i] == 0 && r[i + 1] != 0) {
      r[i] = r[i + 1];
      r[i + 1] = 0;
      i = 0;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (r[i] == r[i + 1] && r[i] != 0) {
      r[i] *= 2;
      r[i + 1] = 0;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (r[i] == 0 && r[i + 1] != 0) {
      r[i] = r[i + 1];
      r[i + 1] = 0;
      i = 0;
    }
  }
  return r;
}
line move_row_right(line r) {
  reverse(r.begin(), r.end());
  r = move_row_left(r);
  reverse(r.begin(), r.end());
  return r;
}
line move_col_up(line r) { return move_row_left(r); }
line move_col_down(line r) {
  reverse(r.begin(), r.end());
  r = move_row_left(r);
  reverse(r.begin(), r.end());

  return r;
}

board move_left(board b) {
  for (int i = 0; i < 4; i++) {
    b.set_row(i, move_row_left(b.row(i)));
  }

  return b;
}
board move_right(board b) {
  for (int i = 0; i < 4; i++) {
    b.set_row(i, move_row_right(b.row(i)));
  }

  return b;
}
board move_up(board b) {
  for (int i = 0; i < 4; i++) {
    b.set_col(i, move_col_up(b.col(i)));
  }

  return b;
}
board move_down(board b) {
  for (int i = 0; i < 4; i++) {
    b.set_col(i, move_col_down(b.col(i)));
  }

  return b;
}

int main() {
  board b;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> b.state[i][j];
    }
  }

  int move;
  cin >> move;

  switch (move) {
  case 0:
    b = move_left(b);
    break;
  case 1:
    b = move_up(b);
    break;
  case 2:
    b = move_right(b);
    break;
  case 3:
    b = move_down(b);
    break;
  }

  for (int i = 0; i < 4; i++) {
    cout << b.state[i][0] << " " << b.state[i][1] << " " << b.state[i][2] << " "
         << b.state[i][3] << endl;
  }
}
