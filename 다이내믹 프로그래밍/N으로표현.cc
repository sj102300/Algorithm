//[Lv3] N으로표현 https://school.programmers.co.kr/learn/courses/30/lessons/42895

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

void push_values(unordered_set<int>& tmp, int a, int b){
    
    tmp.insert(a*b);
    tmp.insert(a/b);
    tmp.insert(a+b);
    tmp.insert(a-b);
    tmp.insert(b-a);
    tmp.insert(b/a);
    
    return;
}

int solution(int N, int number) {
    
    vector<unordered_set<int>> dp(9, unordered_set<int>());
    
    dp[1].insert(N);
    dp[2].insert(N*10+N);
    dp[3].insert(N*100 + N*10 + N);
    dp[4].insert(N*1000 + N*100 + N*10 + N);
    
    
    if(N == number)
        return 1;
    
    int small, large;
    for(int i=2; i<=8; ++i){
        small = 1;
        large = i - small;
        
        while(small <= large){
            for(auto smallv: dp[small]){
                for(auto largev: dp[large]){
                    push_values(dp[i], smallv, largev);
                }
            }
            ++small;
            --large;
        }
        
        if(dp[i].find(0) != dp[i].end()){
            dp[i].erase(0);
        }
        
        if(dp[i].find(number) != dp[i].end())
            return i;
    }
    
    return -1;
}