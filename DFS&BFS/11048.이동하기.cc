//[실버2] 11048.이동하기 https://www.acmicpc.net/problem/11048

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
void getInput(vector<vector<int>> &miro);
int BFS(vector<vector<int>> &miro);

int main(void){
    vector<vector<int>> miro;

    getInput(miro);
    int answer = BFS(miro);
    cout<<answer;
}

void getInput(vector<vector<int>> &miro){
    cin >> n >> m;
    miro.assign(n, vector<int>(m, 0));

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>miro[i][j];
        }
    }
    return;
}

int BFS(vector<vector<int>> &miro){
    vector<vector<int>> visited(n, vector<int>(m, -1));

    int dx[] = {1,0,1};
    int dy[] = {0,1,1};

    queue<pair<int, int>> q;
    visited[0][0] = miro[0][0];
    q.push({0,0});
    int fx, fy, newX, newY;

    while(!q.empty()){
        fx = q.front().first;
        fy = q.front().second;
        q.pop();

        for(int dir=0;dir<3;++dir){
            newX = fx + dx[dir];
            newY = fy + dy[dir];

            if(newX<0 || newY<0 || newX>=n || newY>=m)
                continue;
            
            if(visited[newX][newY] == -1 || visited[newX][newY] < visited[fx][fy] + miro[newX][newY]){
                visited[newX][newY] = visited[fx][fy] + miro[newX][newY];
                q.push({newX, newY});
            }
        }
    }

    return visited[n-1][m-1];
}