//[Lv2] 조이스틱 https://school.programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int answer = 10000000;
vector<bool> isEqual;
int n;

bool completed(vector<bool> &isEqual){
    for(auto v: isEqual){
        if(!v){
            return false;
        }
    }
    return true;
}

void btrk(int cur, int moved){
    if(completed(isEqual)){
        answer = min(moved, answer);
        return;
    }
    
    int leftmove = 0;
    int rightmove = 0;
    int left = cur;
    int right = cur;
    while(isEqual[left]){
        left = (left - 1 + n ) % n;
        leftmove++;
    }
    while(isEqual[right]){
        right = (right + 1) % n ;
        rightmove++;
    }
    
    isEqual[right] = true;
    btrk(right, moved + rightmove);
    isEqual[right] = false;

    isEqual[left] = true;
    btrk(left, moved + leftmove);
    isEqual[left] = false;    
    
}

int solution(string name) {

    int updown = 0;
    vector<int> gap(name.length(), 0);
    isEqual.assign(name.length(), false);
    
    for(int i=0;i<gap.size();++i){
        gap[i] = min(name[i] - 'A', 'Z' - name[i] + 1);
        if(gap[i] == 0){
            isEqual[i] = true;
        }
        updown += gap[i];
    } // 위아래 조작 최솟값
    
    n = name.length();
    
    isEqual[0] = true;
    btrk(0,0);
    
    return answer + updown;
}