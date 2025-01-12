//[실버1] 2667.단지번호붙이기 https://www.acmicpc.net/problem/2667
#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int board[25][25];
int n;
int visited[25][25];

int getTownSize(pair<int, int> start)
{

    queue<pair<int, int>> q;
    int newX, newY;
    pair<int, int> first;
    visited[start.first][start.second] = 1;
    int size = 1;
    q.push(start);

    while (!q.empty())
    {
        first = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            newX = first.first + dx[dir];
            newY = first.second + dy[dir];

            if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                continue;

            if (board[newX][newY] == 1 && visited[newX][newY] == 0)
            {
                visited[newX][newY] = 1;
                q.push({newX, newY});
                ++size;
            }
        }
    }

    return size;
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string tmp;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        for (int j = 0; j < n; ++j)
            board[i][j] = tmp[j] - '0';
    }

    int answer[1000] = {0};
    int answerIdx = 0;

    int townSize = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1 && visited[i][j] == 0)
            {
                answer[answerIdx++] = getTownSize({i, j});
            }
        }
    }

    sort(answer, answer + answerIdx);
    cout<<answerIdx<<"\n";
    for (int i = 0; i < answerIdx; ++i)
        cout << answer[i] << "\n";

    return 0;
}