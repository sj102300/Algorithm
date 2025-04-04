//[Lv2] 전화번호목록 https://school.programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_map<string, int> m; 
    string tmp;
    int last;
    for(auto &v: phone_book){
        tmp = v.substr(0,1);
        last = 1;
        while(tmp.length() < v.length()){
            if(m.find(tmp) == m.end()){ //없으면
                m[tmp] = 1;
            }
            else{
                m[tmp] += 1;
            }
            tmp += v.substr(last, 1);
            ++last;
        }
        if(m.find(v) == m.end()){
            m[tmp] = 1;
        }
        else{
            m[tmp] += 1;
        }
    }
    
    for(auto &v: phone_book){
        if(m[v] != 1)
            return false;
    }
    return true;
}