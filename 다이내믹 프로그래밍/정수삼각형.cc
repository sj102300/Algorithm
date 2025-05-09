//[Lv3] 정수삼각형 https://school.programmers.co.kr/learn/courses/30/lessons/43105

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> triangle) {
    
    vector<vector<int>> dp;
    for(int i=0;i<triangle.size(); ++i){
        dp.push_back(vector<int>(triangle[i].size(), 0));
    }
    
    dp[0][0] = triangle[0][0];
    for(int i=0;i<triangle.size() - 1; ++i){
        for(int j=0;j<triangle[i].size(); ++j){
            dp[i + 1][j] = max(dp[i][j] + triangle[i+1][j], dp[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
        }
    }
    
    int answer = 0;
    
    for(auto v:dp[dp.size()-1]){
        answer = max(answer, v);
    }
    return answer;
}