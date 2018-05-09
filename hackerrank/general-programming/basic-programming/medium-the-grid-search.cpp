/*
  tags: string search, 2d pattern matching
  task: given two matrices, see if one contains the other
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int T; // the number of testcases
  cin >> T;

  while(T--) {
    int R, C; // the number of rows and columns in the first matrix
    cin >> R >> C;

    // we represent the grid as R strings on length C
    vector<string> grid(R);
    for (int i = 0; i < R; i++)
      cin >> grid[i];

    int r, c; // the number of rows and columns in the pattern grid
    cin >> r >> c;

    vector<string> pattern(r);
    for (int i = 0; i < r; i++)
      cin >> pattern[i];

    // we only need to look for the first part of the pattern in the
    // top (R-r) rows of the original pattern (since if it was lower,
    // there would not be enough space for the rest of the pattern)
    bool match = false;

    cerr << "grid is " << R << "x" << C << endl;
    cerr << "pattern is " << r << "x" << c << endl;
    cerr << "looking through first " << R-r << " rows" << endl;

    for (int i = 0; i <= R-r; i++) {
      // if we match the first string of the pattern on this line,
      // dive deeper
      size_t found = string::npos;
      // we keep looking through a line, and try all occurrences of
      // the patterns that we find in that line
      while ((found = grid[i].find(pattern[0], found+1)) != string::npos) {
        // if(found != string::npos) {
        cerr << "found part of pattern on line " << i << " pos " << found << endl;
        cerr << grid[i].substr(found, c) << endl;
        match = true;

        // we found a match for the first line in the pattern, now we
        // check if the rest matches
        for (int j = 1; j < r; j++) {
          if(grid[i+j].compare(found, c, pattern[j], 0, c) == 0) {
            cerr << "line " << j << " of pattern also matches!" << endl;
          } else {
            cerr << grid[i+j].substr(found,c) << " != " << pattern[j] << endl;
            cerr << "line " << j << " of pattern does not match" << endl;
            match = false;
          }
        }

        if(match)
          break;
      }

      if(match)
        break;
    }

    cerr << "result: ";
    if(match) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
