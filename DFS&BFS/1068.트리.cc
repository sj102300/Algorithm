//[골드5] 1068.트리 https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

int n;
int parent[51];
int target;
void getInput(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>parent[i];
    }
    cin>>target;
}

int main(void){
    getInput();

    queue<int> q;

    q.push(target);
    parent[target] = -2;

    while(!q.empty()){
        int first = q.front();
        q.pop();

        for(int i=0;i<n;++i){
            if(parent[i] == first){
                q.push(i);
                parent[i] = -2;
            }
        }
    }

    unordered_set<int> parentSet; 
    int totalNodeNum = 0;
    
    for(int i=0;i<n;++i){
        if(parent[i] >= 0){
            parentSet.insert(parent[i]);
        }
        if(parent[i] != -2){
            totalNodeNum++;
        }
    }

    cout<<totalNodeNum - parentSet.size();
}