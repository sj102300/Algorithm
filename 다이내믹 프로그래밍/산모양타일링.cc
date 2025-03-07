//[Lv3] 산모양타일링 https://school.programmers.co.kr/learn/courses/30/lessons/258705

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> tops) {
    int modulo = 10007;
    
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = tops[0] == 0 ? 3 : 4;
    
    //dp[i] = 윗변기준 i번째의 역삼각형 타일을 붙이는 경우의수
    
    for(int i=2;i<=n;++i){
        dp[i] = dp[i-1] * 3 - dp[i-2];
        if(tops[i-1] == 1){
            dp[i] += dp[i-1];
        }
        dp[i] %= modulo;
        
        if(dp[i] < 0)
            dp[i] += modulo;
    }
    
    return dp[n];
}