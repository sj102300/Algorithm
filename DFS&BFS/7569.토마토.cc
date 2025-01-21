//[골드5] 7569.토마토 https://www.acmicpc.net/problem/7569

#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>

int N, M, H;
int board[102][102][102];

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

typedef struct _node
{
    int x;
    int y;
    int z;
    int day;
} Node;

queue<Node> q;

int answer = 0;

int GetAnswer()
{
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                if (board[i][j][k] == 0)
                    return -1;
            }
        }
    }
    return answer;
}

int main(void)
{

    cin >> M >> N >> H;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                {
                    q.push({i, j, k, 0});
                }
            }
        }
    }

    Node first;
    int newX, newY, newZ;

    while (!q.empty())
    {
        first = q.front();
        q.pop();

        for (int dir = 0; dir < 6; ++dir)
        {
            newX = first.x + dx[dir];
            newY = first.y + dy[dir];
            newZ = first.z + dz[dir];

            if (newX < 0 || newY < 0 || newZ < 0 || newX >= H || newY >= N || newZ >= M)
                continue;

            if (board[newX][newY][newZ] == 0)
            {
                board[newX][newY][newZ] = 1;
                q.push({newX, newY, newZ, first.day + 1});
                answer = max(answer, first.day + 1);
            }
        }
    }

    cout << GetAnswer();

    return 0;
}