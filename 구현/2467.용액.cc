//[골드5] 2567.용액 https://www.acmicpc.net/problem/2467

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

int n;
int arr[100001];

void getInput(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
}

int main(void){

    getInput();

    int left= 0;
    int right=n-1;

    long long mid;
    long long answer = LLONG_MAX;
    long long targetLeft;
    long long targetRight;
    while(left < right){
        mid = arr[left] + arr[right];

        if(mid == 0){
            cout<<arr[left] <<" "<<arr[right];
            return 0;
        }
        else {
            if(abs(mid) < answer){
                answer = abs(mid);
                targetLeft = arr[left];
                targetRight = arr[right];
            }
        }

        if(mid < 0){
            left++;
        }
        else{
            --right;
        }
    }

    cout<<targetLeft<<" "<<targetRight;

}