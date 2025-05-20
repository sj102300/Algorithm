//[골드5] 12865.평범한배낭 https://www.acmicpc.net/problem/12865

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> stuff;

//i만큼의 무게로 j번째 아이템을 고려할때의 최대 가치
int dp[100001][101] = {0};

void getInput(){

    cin>>n>>k;

    stuff.push_back({0,0});

    int w,v;

    for(int i=1;i<=n;++i){
        cin>>w>>v;
        stuff.push_back({w, v});
    }
}

int main(void){

    getInput();

    for(int i=1;i<=k; ++i){ 
        for(int j=1;j<=n;++j){
            int weight = stuff[j].first;
            int value = stuff[j].second;
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(i - weight >= 0){
                dp[i][j] = max(dp[i][j], dp[i-weight][j-1] + value);
            }
        }
    }

    int answer = 0;
    for(int j=1;j<=n;++j){
        answer = max(dp[k][j], answer);
    }
    cout<<answer;
}