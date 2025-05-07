//[실버2] 30804.과일탕후루 https://www.acmicpc.net/problem/30804

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
int n;
int arr[200001];
int eaten[10];

void getInput(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    return;
}

int main(void){
    getInput();

    unordered_set<int> s;

    int maxAnswer=0;
    int curEaten=0;
    int left=0;
    for(int right=0;right<n;++right){
        int fruit = arr[right];
        eaten[fruit]++;
        if(eaten[fruit] == 1){
            s.insert(fruit);
        }
        curEaten++;

        while(s.size() > 2){
            eaten[arr[left]]--;
            curEaten--;
            if(eaten[arr[left]] == 0){
                s.erase(arr[left]);
            }
            left++;
        }
        maxAnswer = max(maxAnswer, curEaten);
    }

    cout<<maxAnswer;
}