//[실버1] 2468.안전영역 https://www.acmicpc.net/problem/2468

#include <iostream>
#include <vector>
using namespace std;
#include <queue>

int n;
vector<vector<int>> board;
vector<vector<int>> visited;
int maxHeight = 0;
int answer = 1;
int dxdy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs(int startX, int startY, int h)
{

    visited[startX][startY] = 1;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(startX, startY));

    pair<int, int> first;
    int newX, newY;

    while (!q.empty())
    {
        {
            first = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                newX = first.first + dxdy[dir][0];
                newY = first.second + dxdy[dir][1];

                if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                    continue;

                if (!visited[newX][newY] && board[newX][newY] > h)
                {
                    visited[newX][newY] = 1;
                    q.push(pair<int, int>(newX, newY));
                }
            }
        }
    }
    return;
}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("/root/LigNex1/Algorithm/cpp/input.txt", "r", stdin);

    cin >> n;

    board.assign(n, vector<int>(n, 0));
    visited.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            maxHeight = max(board[i][j], maxHeight);
        }
    }

    int cnt;
    for (int h = 1; h < maxHeight; ++h)
    {
        cnt = 0;
        visited.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && board[i][j] > h)
                {
                    bfs(i, j, h);
                    ++cnt;
                }
            }
        }
        answer = max(answer, cnt);
    }

    cout<<answer;
    return 0;
}