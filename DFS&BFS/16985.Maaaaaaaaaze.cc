//[골드2] 16985.Maaaaaaaaaze https://www.acmicpc.net/problem/16985

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<vector<vector<int>>>> boards(5, vector<vector<vector<int>>>(4, vector<vector<int>>(5, vector<int>(5, -1))));

vector<int> visited(5, 0);
typedef struct point
{
    int x, y, z;
} Point;

int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int answer = 1000000;

void printBoard(int a, int b)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << boards[a][b][i][j];
        }
        cout << "\n";
    }
}

void rotateBoard(int a, int b)
{
    vector<vector<int>> *pt = &boards[a][b];
    vector<vector<int>> *prev = &boards[a][b - 1];

    for (int j = 4; j >= 0; --j)
        for (int i = 0; i < 5; ++i)
            (*pt)[i][j] = (*prev)[5 - j - 1][i];
}

void btrk(int first, int second, int third, int fourth, int fifth, int n, vector<int> history)
{

    if(answer == 12){
        return;
    }
    
    if (n == 5)
    {
        vector<vector<vector<int>>> newBoard(5, vector<vector<int>>(5, vector<int>(5, 0)));

        queue<Point> q;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                newBoard[0][i][j] = boards[history[0]][first][i][j];
                newBoard[1][i][j] = boards[history[1]][second][i][j];
                newBoard[2][i][j] = boards[history[2]][third][i][j];
                newBoard[3][i][j] = boards[history[3]][fourth][i][j];
                newBoard[4][i][j] = boards[history[4]][fifth][i][j];
            }
        }

        if (newBoard[0][0][0] == -2 || newBoard[4][4][4] == -2)
            return;

        Point first;
        q.push({0, 0, 0});
        newBoard[0][0][0] = 0;

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

                  if (newX < 0 || newY < 0 || newZ < 0 || newX >= 5 || newY >= 5 || newZ >= 5)
                        continue;

                if (newBoard[newX][newY][newZ] == -1 || newBoard[newX][newY][newZ] > newBoard[first.x][first.y][first.z] + 1)
                {
                    newBoard[newX][newY][newZ] = newBoard[first.x][first.y][first.z] + 1;
                    q.push({newX, newY, newZ});
                }
            }
        }

        if (newBoard[4][4][4] != -1) {
            answer = min(answer, newBoard[4][4][4]);
        }

        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            history.push_back(i);
            btrk(first, second, third, fourth, fifth, n + 1, history);
            history.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("/root/LigNex1/Algorithm/cpp/input.txt", "r", stdin);

    int tmp;
    for (int n = 0; n < 5; ++n)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cin >> tmp;
                boards[n][0][i][j] = tmp == 0 ? -2 : -1;
            }
        }
    }

    for (int a = 0; a < 5; ++a)
        for (int b = 1; b < 4; ++b)
            rotateBoard(a, b);

    for (int first = 0; first < 4; ++first)
    {
        for (int second = 0; second < 4; ++second)
        {
            for (int third = 0; third < 4; ++third)
            {
                for (int fourth = 0; fourth < 4; ++fourth)
                {
                    for (int fifth = 0; fifth < 4; ++fifth)
                    {
                        vector<int> history;
                        btrk(first, second, third, fourth, fifth, 0, history);
                    }
                }
            }
        }
    }

    if (answer == 1000000)
        cout << "-1";
    else
        cout<<answer;
}