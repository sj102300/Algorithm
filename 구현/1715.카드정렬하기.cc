//[골드4] 1715.카드정렬하기 https://www.acmicpc.net/problem/1715

#include<iostream>
#include<queue>
using namespace std;

int main(void){

    int n;
    priority_queue<int, vector<int>, greater<int>> q; // 최소 힙

    cin>>n;
    int tmp;
    for(int i=0;i<n;++i){
        cin>>tmp;
        q.push(tmp);
    }

    int answer = 0;
    int first, second;
    for(int i=0;i<n-1;++i){
        first = q.top();
        q.pop();
        second = q.top();
        q.pop();
        tmp = first+second;
        q.push(tmp);
        answer+= tmp;
    }

    cout<<answer;

    return 0;
}