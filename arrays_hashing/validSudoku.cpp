#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
  for (int j = 0; j < 9; j++) {
    vector<bool> h(9, false), v(9, false), g(9, false);
    int gridJ = j / 3;
    int gridI = j % 3;
    for (int i = 0; i < 9; i++) {
      if (board[j][i] != '.') {
        if (h[board[j][i] - '0'])
          return false;
        else
          h[board[j][i] - '0'] = true;
      }
      if (board[i][j] != '.') {
        if (v[board[i][j] - '0'])
          return false;
        else
          v[board[i][j] - '0'] = true;
      }
      int y = (gridJ * 3) + (int)(i / 3);
      int x = (gridI * 3) + (int)(i % 3);
      if (board[y][x] != '.') {
        if (g[board[y][x] - '0'])
          return false;
        else
          g[board[y][x] - '0'] = true;
      }
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  vector<vector<char>> board{{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                             {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
                             {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
                             {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
  cout << isValidSudoku(board);
  return 0;
}
