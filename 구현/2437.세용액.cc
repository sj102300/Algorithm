//[골드3] 2437.세용액 https://www.acmicpc.net/problem/2473

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n;
long long arr[5001];

void getInput(){

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
}

long long myabs(long long a){
    return a>0? a: -a;
}

int main(void){

    getInput();

    sort(arr, arr+n);

    long long answer = LLONG_MAX;
    long long targetLeft = arr[0];
    long long targetRight = arr[2];
    long long targetMid = arr[1];

    for(int left = 0;left<n-2; ++left){
        int mid = left+1;
        int right = n-1;

        while(mid < right){
            if(arr[left] + arr[mid] + arr[right] == 0){
                cout<<arr[left]<<" "<<arr[mid] <<" "<<arr[right];
                return 0;
            }
            else if(myabs(arr[left] + arr[mid] + arr[right]) < answer){
                targetLeft = arr[left];
                targetMid = arr[mid];
                targetRight = arr[right];
                answer = myabs(arr[left] + arr[mid] + arr[right]);
            }

            if(arr[left] + arr[mid] + arr[right] < 0){
                mid++;
            }
            else{
                right--;
            }
        }
    }

    cout<<targetLeft<<" "<<targetMid<<" "<<targetRight;

    return 0;
}