// https://leetcode.com/problems/sudoku-solver

// Bad practice, just doing this for competitive programming!
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(vector<vector<char>>& board, int r, int c, char value) {
    for (int i = 0; i < 9; i++) {
      if (board[i][c] == value) {
        return false;
      }
    }

    for (int i = 0; i < 9; i++) {
      if (board[r][i] == value) {
        return false;
      }
    }

    int subi = r / 3 * 3;
    int subj = c / 3 * 3;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i + subi][j + subj] == value) {
          return false;
        }
      }
    }
    return true;
  }
  bool solveSudohelper(vector<vector<char>>& board, int i, int j) {
    // you are at index (3,3) so next time u move to (3,4) but if you are at
    // (3,8) ,u do (4,0)
    if (i == board.size()) {
      return true;
    }
    int ni = 0;
    int nj = 0;
    if (j == board.size()) {
      nj = 0;
      ni = i + 1;
    } else {
      nj = j + 1;
      ni = i;
    }

    if (board[i][j] != '.') {
      return solveSudohelper(board, ni, nj);
    } else {
      // all possible values are 1 to 9
      for (char po = '1'; po <= '9'; po++) {
        // cout<<"po is "<<po<<endl;
        if (isValid(board, i, j, po) == true) {
          board[i][j] = po;
          if(solveSudohelper(board, ni, nj)) return true;
          board[i][j] = '.';
        }
      }
    }
    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    solveSudohelper(board, 0, 0);
  }
};