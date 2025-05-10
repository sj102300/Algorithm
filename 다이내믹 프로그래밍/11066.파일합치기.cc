//[골드3] 11066.파일합치기 https://www.acmicpc.net/problem/11066

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int t;
int n;
int arr[501];
int dp[501][501];
int sum[501];

int main(void){

    cin>>t;

    int tmp;
    for(int _=0;_<t;++_){
        cin>>n;
        int answer = 0;
        for(int i=1;i<=n;++i){
            cin>>tmp;
            sum[i] = sum[i-1] + tmp;
        }

        for(int i=1;i<=n;++i){
            dp[i][i] = 0;
        }

        //dp[i][j] i부터 j까지 합치는데 드는 최소 비용
        for(int gap = 1; gap<=n-1; ++gap){
            for(int s = 1;s+gap<=n;++s){
                int e = s+gap;
                dp[s][e] = INT_MAX;

                for(int i=s;i<e;++i){
                    dp[s][e] = min(dp[s][e], dp[s][i] + dp[i+1][e] + sum[e] - sum[s-1]);
                }
            }
        }

        cout<<dp[1][n]<<endl;

    }
}