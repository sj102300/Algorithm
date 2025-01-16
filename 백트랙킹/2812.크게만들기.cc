//[골드3] 2812.크게만들기 https://www.acmicpc.net/problem/2812
#include<iostream>
#include<sstream>
using namespace std;

int n, k;
int arr[500001];

int findMaxIdx(int s, int e){
    
    int result = s;

    for(int i=s;i<=e;++i){
        if (arr[result] == 9)
            return result;
        if (arr[result] < arr[i])
            result = i;
    }
    return result;
}

void btrk(int s, int e, int k){
    if(k == 0){
        for(;s<n;++s)
            cout<<arr[s];
        return;
    }
    if (e>=n){
        return;
    }

    int maxIdx = findMaxIdx(s, e);
    cout<<arr[maxIdx];
    k = k - maxIdx + s;
    s = maxIdx+1;
    e= s+k;
    btrk(s,e,k);    
    return;
}

int main(void){

    cin>>n>>k;
    string tmp;
    cin>>tmp;

    for(int i=0;i<n;++i){
        arr[i] = tmp[i]-'0';
    }

    btrk(0, k, k);

}