//[골드5] 16935.배열돌리기3 https://www.acmicpc.net/problem/16935

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> tmpboard;
int N, M, maxNM;

void printBoard(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j)
      cout << board[i][j] << " ";
    cout << "\n";
  }
}

void first(int n, int m) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      tmpboard[i][j] = board[n - i - 1][j];
    }
  }
  board.swap(tmpboard);
  return;
}

void second(int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      tmpboard[i][j] = board[i][m - 1 - j];
  }
  board.swap(tmpboard);
  return;
}

void third(int n, int m) {
  
  for (int j = n-1; j>=0; --j) {
    for (int i = 0; i<m;i++) {
      tmpboard[i][j] = board[n - 1 - j][i];
    }
  }
  board.swap(tmpboard);
  swap(N, M);
  return;
}

void fourth(int n, int m) {

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i)
      tmpboard[i][j] = board[j][m - 1 - i];
  }
  board.swap(tmpboard);
  swap(N, M);
  return;
}

void copyBoard(int n, int m, int tx, int ty, int ax, int ay) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      tmpboard[tx + i][ty + j] = board[ax + i][ay + j];
  }
  return;
}

void fifth(int n, int m) {
  int halfN = n / 2;
  int halfM = m / 2;

  copyBoard(halfN, halfM, 0, halfM, 0, 0);
  copyBoard(halfN, halfM, halfN, halfM, 0, halfM);
  copyBoard(halfN, halfM, halfN, 0, halfN, halfM);
  copyBoard(halfN, halfM, 0, 0, halfN, 0);

  board.swap(tmpboard);
  return;
}
void sixth(int n, int m) {

  int halfN = n / 2;
  int halfM = m / 2;

  copyBoard(halfN, halfM, halfN, 0, 0, 0);
  copyBoard(halfN, halfM, 0, 0, 0, halfM);
  copyBoard(halfN, halfM, 0, halfM, halfN, halfM);
  copyBoard(halfN, halfM, halfN, halfM, halfN, 0);

  board.swap(tmpboard);
  return;
}

int main(void) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int r;
  cin >> N >> M >> r;

  maxNM = max(N, M);

  board.assign(maxNM, vector<int>(maxNM, 0));
  tmpboard.assign(maxNM, vector<int>(maxNM, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  void (*operations[6])(int n, int m) = {first,  second, third,
                                         fourth, fifth,  sixth};

  int op;
  for (int i = 0; i < r; i++) {
    cin >> op;
    operations[op - 1](N, M);
  }

  printBoard(N, M);
}