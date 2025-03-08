//[Lv2] 더맵게 https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <queue>
#include <functional>
 
using namespace std;

int solution(vector<int> scoville, int K) {
    
    priority_queue pq{greater<int>{}, scoville};
    
    int first;
    int second;
    int mixValue;
    int mixCnt = 0;
    while(pq.size() > 1){
        first = pq.top();
        if(first >= K){
            return mixCnt;
        }
        pq.pop();
        second = pq.top();
        pq.pop();
        ++mixCnt;
        mixValue = first + second * 2;
        pq.push(mixValue);
    }
    
    if(pq.top() >= K){
        return mixCnt;
    }
    else{
        return -1;
    }
}