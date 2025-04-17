//[골드4] 1647.도시분할계획 https://www.acmicpc.net/problem/1647

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

typedef struct _edge{
    int start;
    int end;
    int weight;
} Edge;

int n, m;
Edge edges[1000001];
int parent[100001];
int cost[100001];
int maxCost = INT_MIN;

void getInput(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>edges[i].start>>edges[i].end>>edges[i].weight;
    }
    for(int i=1;i<=n;++i){
        parent[i] = i;
    }
}

bool comp(Edge &a, Edge&b){
    return a.weight < b.weight;
}

int find(int a){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = find(parent[a]);
}

bool myunion(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(pa < pb){
        parent[pb] = pa;
    }
    else if(pa > pb){
        parent[pa] = pb;
    }
    else{
        return false;
    }        //이미 같은 그룹
    return true;
}

void print(){
    for(int i=1;i<=n;++i){
        cout<<parent[i]<< " ";
    }cout<<endl;
}

int main(void){

    getInput();

    sort(edges, edges+m, comp);

    long long total = 0;

    for(int i=0;i<m;++i){
        if(myunion(edges[i].start, edges[i].end)){
            total += edges[i].weight;
            maxCost = max(edges[i].weight, maxCost);
        }
    }

    cout<<total - maxCost;

}