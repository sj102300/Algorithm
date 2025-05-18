//[골드3] 7579.앱 https://www.acmicpc.net/problem/7579

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int memory[102];
int cost[102];
int dp[10001][101];
int costSum=0;

void getInput(){
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        cin>>memory[i];
    }
    for(int i=1;i<=n;++i){
        cin>>cost[i];
        costSum+=cost[i];
    }
}

int main(void){

    getInput();

    int answer = -1;

    for(int i=0;i<=costSum;++i){
        for(int j=1;j<=n;++j){
            dp[i][j] = dp[i][j-1];
            if(i - cost[j] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-cost[j]][j-1] + memory[j]);
            }
        }
    }

    // for(int i=0;i<=costSum;++i){
    //     for(int j=0;j<=n;++j){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }

    for(int i = 0; i <= costSum; ++i){
        if(dp[i][n] >= m){
            answer = i;
            break;
        }
    }

    cout<<answer;

}