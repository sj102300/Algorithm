//[Lv1] 개인정보수집유효기간 https://school.programmers.co.kr/learn/courses/30/lessons/150370

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int changeDateToInt(string str){
    int y = stoi(str.substr(0,4));
    int m = stoi(str.substr(5,2));
    int d = stoi(str.substr(8));
    
    int ret = d + (m-1) * 28 + (y - 2000) * 12 * 28;
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    unordered_map<char, int> termMap;
    char ch;
    int m;
    for(auto & term:terms){
        ch = term[0];
        m = stoi(term.substr(2));
        termMap[ch] = m;
    }
    
    string day;
    int dayNum;
    char term;
    int months;
    int todayNum = changeDateToInt(today);
    vector<int> answer;
    for(int i=0;i<privacies.size();++i){
        string privacy = privacies[i];
        day = privacy.substr(0, 10);
        dayNum = changeDateToInt(day);
        term = privacy[11];
        months = termMap.find(term)->second;
        if(todayNum > dayNum + 28 * months - 1){
            answer.push_back(i+1);
        }
        
    }
    
    return answer;
}