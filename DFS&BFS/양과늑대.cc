//[Lv3] 양과늑대 https://school.programmers.co.kr/learn/courses/30/lessons/92343

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int answer;

void printVector(vector<int>& tmp){
    for(auto v : tmp){
        cout<< v << " ";
    }
    cout<<"\n";
}

void DFS(int start, vector<int> connected, int sheep, int wolf, vector<int>& info){
    if(sheep <= wolf){
        //early exit
        return;
    }
    
    answer = max(answer, sheep);
    
    // if(){} //종료조건 필요
    vector<int> tmp;
    
    vector<int> target = graph[start];
    target.insert(target.end(), connected.begin(), connected.end());
    
    for(auto node = target.begin(); node != target.end(); node++){
        if(!visited[*node]){
            visited[*node] = true;
            tmp.clear();
            for(auto v: target){
                if(!visited[v]){
                    tmp.push_back(v);
                }
            }
            // cout<<"start: " <<start<<endl;
            // cout<<"tmp: ";
            // printVector(tmp);
            // cout<<sheep << " "<< wolf<<endl;
            if(info[*node] == 0){
                DFS(*node, tmp, sheep+1, wolf, info);
            }
            else{
                DFS(*node, tmp, sheep, wolf+1, info);
            }
            visited[*node] = false;
        }
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) {
    visited.assign(info.size(), false);
    graph.assign(info.size(), {});
    
    for(auto edge = edges.begin(); edge != edges.end(); edge++){
        graph[(*edge)[0]].push_back((*edge)[1]);
        graph[(*edge)[1]].push_back((*edge)[0]);
    }
    
    visited[0] = true;
    
    // DFS();
    DFS(0, {}, 1, 0, info);
    
    return answer;
}