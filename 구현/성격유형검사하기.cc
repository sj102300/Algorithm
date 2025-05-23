//[Lv1] 성격유형검사하기 https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    int scores[8] = {0, 3,2,1,0,1,2,3};
    
    unordered_map<char, int> cur;
    
    cur['R'] = 0;
    cur['T'] = 0;
    cur['C'] = 0;
    cur['F'] = 0;
    cur['J'] = 0;
    cur['M'] = 0;
    cur['A'] = 0;
    cur['N'] = 0;
    
    for(int i =0;i<survey.size(); ++i){
        char prev = survey[i][0];
        char next = survey[i][1];
        if(choices[i] == 4){
            continue;
        }
        else if(choices[i] < 4){
            cur[prev] += scores[choices[i]];
        }
        else {
            cur[next] += scores[choices[i]];
        }
    }
    string answer = "";
    
    if(cur['R'] >= cur['T']){
        answer+="R";
    }
    else{
        answer+="T";
    }
    
    if(cur['C'] >= cur['F']){
        answer+="C";
    }
    else{
        answer+="F";
    }
    
    if(cur['J'] >= cur['M']){
        answer += "J";
    }
    else{
        answer += "M";
    }
    
    if(cur['A'] >= cur['N']){
        answer += "A";
    }
    else{
        answer += "N";
    }
    
    return answer;
}