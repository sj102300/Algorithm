//[실버2] 10164.격자상의경로 https://www.acmicpc.net/problem/10164

#include <iostream>
#include <algorithm>
using namespace std;

int dp[18][18];
int n, m, k;

int sol(pair<int, int> start, pair<int, int> end){

    for(int i=start.first;i<=end.first;++i)
        dp[i][start.second] = 1;
    for(int j=start.second;j<=end.second;++j)
        dp[start.first][j] = 1;


    for(int i=start.first+1; i<=end.first;++i){
        for(int j=start.second+1;j<=end.second;++j){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[end.first][end.second];
}

int main(void){
    cin>>n>>m>>k;
    if(k ==0 ){
        cout<<sol({0,0}, {n-1, m-1});
    }
    else{
        pair<int, int> center = {(k-1)/m, (k-1)%m};
        cout<<sol({0,0}, center)* sol(center, {n-1, m-1});
    }
}