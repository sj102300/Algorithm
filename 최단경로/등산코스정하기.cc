//[Lv3] 등산코스정하기 https://school.programmers.co.kr/learn/courses/30/lessons/118669

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;
unordered_set<int> summitset;
vector<vector<pair<int, int>>> graph;
struct comp{
    bool operator()(pair<int, int> a, pair<int, int>b){
        return a.second > b.second;
    }
};

int N;
//노드, 비용
priority_queue<pair<int, int>, vector<pair<int,int>>,  comp> pq;
vector<int> intensitys;
vector<bool> isSummits;

bool compare(pair<int, int>a, pair<int, int> b){
    if(a.second < b.second){
        return true;
    }
    else if (a.second == b.second){
        return a.first < b.first;
    }
    else {
        return false;
    }
}

pair<int, int> dijkstra(){
    
    vector<pair<int, int>> answers;
    
    pair<int, int> front;
    while(!pq.empty()){
        front = pq.top();
        pq.pop();
        
        int fnode = front.first;
        int fweight = front.second;
        
        if(fweight > intensitys[fnode])
            continue;
        
        if(isSummits[fnode]){
            answers.push_back({fnode, fweight});
            continue;
        }
        
        for(auto v: graph[fnode]){
            int vNode = v.first;
            int vWeight = v.second;
            if(intensitys[vNode] == -1 || intensitys[vNode] > max(fweight, vWeight)){
                    intensitys[vNode] = max(fweight, vWeight);
                pq.push({vNode, intensitys[vNode]});
            }
        }
    }

    sort(answers.begin(), answers.end(), compare);

    return answers[0];
    
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    N = n;
    graph.assign(N+1, {});
    intensitys.assign(N+1, -1);
    isSummits.assign(N+1, false);
    
    vector<bool> isGates(N+1, false);
    
    for(auto path: paths){
        graph[path[0]].push_back({path[1], path[2]});
        graph[path[1]].push_back({path[0], path[2]});
    }
    
    for(auto g:gates){
        intensitys[g] = 0;
        pq.push({g, 0});
    }
    
    for(auto s:summits){
        isSummits[s] = true;
    }
    
    pair<int, int> ret = dijkstra();
    vector<int> answer = {ret.first, ret.second};
    return answer;
}