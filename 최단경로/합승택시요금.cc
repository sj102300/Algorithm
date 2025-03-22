//[Lv3] 합승택시요금 https://school.programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

struct NodeInfo{
    int node;
    int weight;
};

int N;
vector<vector<NodeInfo>> graph;

struct comp{
    bool operator()(NodeInfo a, NodeInfo b){
        return a.weight > b.weight;
    }
};

void dijkstra(vector<int> & dist, int start){
    vector<bool> visited(N+1, false);
    
    dist[start] = 0;
    priority_queue<NodeInfo, vector<NodeInfo>, comp> pq;
    
    pq.push({start, 0});
    
    NodeInfo first;
    while(!pq.empty()){
        first = pq.top();
        pq.pop();
        
        if(visited[first.node]){
            continue;
        }
        
        visited[first.node] = true;
        for(auto v : graph[first.node]){
            if(dist[v.node] > dist[first.node] + v.weight){
                dist[v.node] = dist[first.node] + v.weight;
                pq.push({v.node, dist[v.node]});
            }
        }
    }
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    N=n;
    //그래프 만들기    
    int c, d, f;
    graph.assign(n+1, {});
    for(auto fare: fares){
        c = fare[0];
        d = fare[1];
        f = fare[2];

        graph[c].push_back({d, f});
        graph[d].push_back({c, f});
    }
    
    vector<int> distA(n+1, INT_MAX);
    vector<int> distB(n+1, INT_MAX);
    vector<int> distS(n+1, INT_MAX);
    
    dijkstra(distS, s);
    dijkstra(distA, a);
    dijkstra(distB, b);
    
    int answer = INT_MAX;
    for(int i=1;i<=n; ++i){
        if(distA[i] == INT_MAX || distB[i] == INT_MAX || distS[i] == INT_MAX)
            continue;
        answer = min(answer, distA[i] + distB[i] + distS[i]);
    }
    
    return answer;
}