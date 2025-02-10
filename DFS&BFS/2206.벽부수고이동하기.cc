//[골드3] 2206.벽부수고이동하기 https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;

int board[1001][1001];
int visited[1001][1001][2];
int n, m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void getInput(){
    cin>>n>>m;
    string tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        for(int j=0;j<m;++j){
            board[i][j] = tmp[j] - '0';
        }
    }
}

void printVisited(){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout<<visited[i][j][0]<<" ";
        }cout<<"\n";
    }
}


int bfs(){

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0,0,0));

    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    int newX, newY;
    int x, y, isbroken;
    while(!q.empty()){
        tie(x,y,isbroken) = q.front();
        q.pop();

        for(int dir=0;dir<4;++dir){
            newX = x + dx[dir];
            newY = y + dy[dir];

            if(newX <0 || newY <0 || newX >= n || newY >= m)
                continue;

            //벽일때 부수고 감
            if(board[newX][newY] == 1){
                if(!isbroken && (visited[newX][newY][1] == 0 || visited[newX][newY][1] > visited[x][y][0] + 1)){
                    q.push({newX, newY, 1});
                    visited[newX][newY][1] = visited[x][y][0] + 1;
                } 
            }

            //벽아닐때 통과하기
            else{
                if(isbroken){
                    if(visited[newX][newY][1] == 0 || visited[newX][newY][1] > visited[x][y][1] + 1){
                        q.push({newX, newY, 1});
                        visited[newX][newY][1] = visited[x][y][1]+1;
                    }
                }
                else {
                    if(visited[newX][newY][0] == 0 || visited[newX][newY][0] > visited[x][y][0] + 1){
                        q.push({newX, newY, 0});
                        visited[newX][newY][0] = visited[x][y][0] + 1;
                    }
                }
            }
        }        
    }   

    if(visited[n-1][m-1][0] != 0 && visited[n-1][m-1][1] != 0){
        return min(visited[n-1][m-1][0], visited[n-1][m-1][1]);
    }
    else if (visited[n-1][m-1][0] == 0 && visited[n-1][m-1][1] != 0){
        return visited[n-1][m-1][1];
    }
    else if(visited[n-1][m-1][1] == 0 && visited[n-1][m-1][0] != 0){
        return visited[n-1][m-1][0];
    }
    else{
        return -1;
    }
}

int main(void){
    
    getInput();

    cout<<bfs();
}