//[실버3] 11727.2xn타일링2 https://www.acmicpc.net/problem/11727

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int main(void){
    int n;
    cin>>n;
    dp[1] = 1;
    dp[2] = 3;

    for(int i=3;i<=n; ++i){
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }

    cout<<dp[n];
}