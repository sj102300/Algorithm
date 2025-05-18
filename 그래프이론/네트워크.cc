//[Lv3] 네트워크 https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int find(int a, vector<int> &parent){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a], parent);     //여기서 parent[a]를 호출해주어야함!
}

void myunion(int a, int b, vector<int> &parent){
    int pa = find(a, parent);
    int pb = find(b, parent);
    
    if(pa<pb){
        parent[pb] = pa;
    }
    else if(pa>pb){
        parent[pa] = pb;
    }
    else{
        return;
    }
}


int solution(int n, vector<vector<int>> computers) {
    
    vector<int> parent(n);
    for(int i=0;i<n;++i){
        parent[i] = i;
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i == j)    continue;
            if(computers[i][j] == 1){
                myunion(i, j, parent);
            }
        }
    }
    
    unordered_set<int> answer;
    for(int i=0; i<n;++i){
        int p = find(i, parent);
        if(answer.find(p) == answer.end()){
            answer.insert(p);
        }
    }
    
    return answer.size();
}