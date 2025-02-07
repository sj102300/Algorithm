//[골드5] 2240.자두나무 https://www.acmicpc.net/problem/2240

#include <iostream>
#include <algorithm>
using namespace std;

int t,w;
int dp[1001][3][31];
int jadu[1001][3];

void getInput(){
    cin>> t>>w;
    int tmp;
    for(int time=1;time<=t;++time){
        cin>>tmp;
        jadu[time][tmp] = 1;
    }
}

void printdp(){
    for(int i=0;i<=t;++i){
        for(int j=1;j<=2;++j){
            for(int k=0;k<=w;++k){
                cout<<"i, j, k, dp value:"<<i<<" "<<j<<" " <<k <<" ["<<dp[i][j][k] <<"]\n";
            }
        }
    }
}

int main(void){

    getInput();

    int answer = 0;

    for(int i=1;i<=t;++i){
        dp[i][1][0] = dp[i-1][1][0] + jadu[i][1];
        answer = max(answer, dp[i][1][0]);
    }

    for(int i=1;i<=t;++i){
        for(int k=1;k<=w;++k){
            dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][2][k-1]) + jadu[i][1];
            dp[i][2][k] = max(dp[i-1][2][k], dp[i-1][1][k-1]) + jadu[i][2];
            answer = max(answer, dp[i][1][k]);
            answer = max(answer, dp[i][2][k]);
        }
    }

    cout<<answer;
    // printdp();

}