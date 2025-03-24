//[Lv3] 광고삽입 https://school.programmers.co.kr/learn/courses/30/lessons/72414

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int changeTimeToInt(string str){
    
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6));
    
    return h * 60 * 60 + m * 60 + s;
}

string changeIntToTime(int time){
    int s = time % 60;
    int m = time / 60 % 60;
    int h = time / 3600;
    
    string sh = h >= 10 ? to_string(h) : "0" + to_string(h);
    string sm = m >= 10 ? to_string(m) : "0" + to_string(m);
    string ss = s >=10 ? to_string(s) : "0" + to_string(s);
    
    return sh + ":" + sm + ":" + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    int maxTime = changeTimeToInt(play_time);
    vector<long long> dp(maxTime + 1, 0);
    
    vector<int> starts;
    vector<int> ends;
    for(auto log: logs){
        starts.push_back(changeTimeToInt(log.substr(0, 8)));
        ends.push_back(changeTimeToInt(log.substr(9)));
    }
    
    for(auto s: starts){
        ++dp[s];
    }
    for(auto e: ends){
        --dp[e];
    }
    
    for(int i=1;i<=maxTime;++i){
        dp[i] = dp[i-1] + dp[i];
    }
    
    int advTime = changeTimeToInt(adv_time);
    
    long long curValue = 0;
    for(int i=0;i<advTime;++i){
        curValue += dp[i];
    }
    
    int left=0;
    int right=advTime - 1;
    
    long long maxValue = curValue;
    int answerSec = 0;
    
    while(right < maxTime){
        curValue -= dp[left];
        left++;
        right++;
        curValue += dp[right];
        if(maxValue < curValue){
            maxValue = curValue;
            answerSec = left;
        }
    }
    
    return changeIntToTime(answerSec);
}