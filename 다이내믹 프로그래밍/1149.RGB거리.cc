//[실버1] 1149.RGB거리 https://www.acmicpc.net/problem/1149

#include <iostream>
#include <string>
#include <climits>

using namespace std;

int n;
int rgb[1001][3];
int dp[1001][3];

void getInput(){

    cin>>n;
    int r, g, b;
    for(int i=0;i<n;++i){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    
}

int main(void){

    getInput();

    for(int i=0;i<3;++i){
        dp[0][i] = rgb[0][i];
    }

    for(int i=1;i<n;++i){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + rgb[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];
    }

    int answer = INT_MAX;
    for(int i=0;i<3;++i){
        answer = min(answer, dp[n-1][i]);
    }
    cout<<answer;
}