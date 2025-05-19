//[실버1] 2156.포도주시식 https://www.acmicpc.net/problem/2156

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int juice[10001] = {0};
int dp[10001][3] = {0};

void getInput(){
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>juice[i];
    }
}

int main(void){

    getInput();

    dp[0][0] = juice[0];

    for(int i=1;i<n;++i){
        dp[i][0] = dp[i-1][2] + juice[i];
        dp[i][1] = dp[i-1][0] + juice[i];
        dp[i][2] = max(dp[i-1][2], max(dp[i-1][1], dp[i-1][0]));
    }

    int answer = 0;
    for(int i=0;i<3;++i){
        answer = max(answer, dp[n-1][i]);
    }
    cout<<answer;
}