//[실버2] 2304.창고다각형 https://www.acmicpc.net/problem/2304

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[1001];
int visited[1001];
int n;
int maxHeight = -1;

void getInput(){
    cin>>n;
    
    int a, b;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        arr[a] = b;
    }

}

int main(void){
    
    getInput();

    visited[1] = arr[1];
    for(int i=1;i<=1000; ++i){
        visited[i] = max(arr[i], visited[i-1]);
        maxHeight = max(arr[i], maxHeight);
    }

    visited[1000] = arr[1000];
    for(int i=999 ; i>=1;--i){
        visited[i] = max(arr[i], visited[i+1]);
        if(visited[i] == maxHeight){
            break;
        }
    }

    int sum=0;
    for(int i=1;i<=1000;++i){
        sum+=visited[i];
    }
    cout<<sum;

}