//[Lv2] 미로탈출 https://school.programmers.co.kr/learn/courses/30/lessons/159993

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int BFS(vector<string> &maps, pair<int, int>start, pair<int, int>end){
    
    int newX, newY;
    pair<int, int> first;
    queue<pair<int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> visited(n, vector<int>(m,-1));
    
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    
    q.push(start);
    visited[start.first][start.second] = 0;
    
    while(!q.empty()){
        first = q.front();
        q.pop();
        
        for(int dir= 0;dir<4;++dir){
            newX = first.first + dx[dir];
            newY = first.second + dy[dir];
            
            if(newX <0 || newY <0 || newX >=n || newY >= m|| maps[newX][newY] == 'X')
                continue;
            
            if(visited[newX][newY] == -1 || 
                    visited[newX][newY] > visited[first.first][first.second] + 1){
                visited[newX][newY] = visited[first.first][first.second] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    return visited[end.first][end.second];
    
}

int solution(vector<string> maps) {
    
    pair<int, int> start, end, lever;
    
    for(int i=0;i<maps.size(); ++i){
        for(int j=0;j<maps[i].size(); ++j){
            if(maps[i][j] == 'S'){
                start = {i,j};
            }
            else if(maps[i][j] == 'E'){
                end = {i,j};
            }
            else if(maps[i][j] == 'L'){
                lever = {i,j};
            }
        }
    }

    int startToLever = BFS(maps, start, lever);
    int leverToEnd = BFS(maps, lever, end);

    if(startToLever < 0 || leverToEnd < 0)
        return -1;

    return startToLever + leverToEnd;
}