//[Lv3] 네트워크 https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>&computers, vector<bool>&visited){

    visited[start] = true;
    
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int f = q.front();
        q.pop();
        
        for(int i=0;i<computers[f].size();++i){
            if(computers[f][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    vector<bool> visited(n, false);
    int answer = 0;
    
    for(int i=0;i<n;++i){
        if(!visited[i]){
            bfs(i, computers, visited);
            answer++;
        }
    }
    
    return answer;
}