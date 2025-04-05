//[Lv2] 구명보트 https://school.programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());

    int left =0;
    int right = people.size() - 1;
    
    int answer = 0;
    
    while(left<=right){
        if(people[left] + people[right] <= limit){
            ++left;
            --right;
            ++answer;
        }
        else {
            --right;
            answer++;
        }
    }
    
    return answer;
}