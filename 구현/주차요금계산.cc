//[Lv2] 주차요금계산 https://school.programmers.co.kr/learn/courses/30/lessons/92341

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

void parseString(string& str, vector<string> & record){
    
    record.clear();
    istringstream input;
    input.str(str);
    for (std::string line; std::getline(input, line, ' '); ){
        record.push_back(line);
    }
    return;
}

int calcTime(string&inTime, string& outTime){
    
    int inHour = stoi(inTime.substr(0, 2));
    int inMin = stoi(inTime.substr(3)) + inHour * 60;
    int outHour = stoi(outTime.substr(0,2));
    int outMin = stoi(outTime.substr(3)) + outHour * 60;
    
    return outMin - inMin;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    
    //차량번호, 누적 시간
    unordered_map<string, int> carsTime;
    
    //차량번호, 입차시간
    unordered_map<string, string> cur;
    
    vector<string> tmp;
    
    for(auto &s:records){
        parseString(s, tmp);
        
        if(tmp[2] == "OUT"){
            string inTime = cur[tmp[1]];
            string outTime = tmp[0];
            cur.erase(tmp[1]);
            int stayTime = calcTime(inTime, outTime);
            if(carsTime.find(tmp[1]) != carsTime.end()){
                carsTime[tmp[1]] += stayTime;
            }
            else{
                carsTime[tmp[1]] = stayTime;
            }
        }
        else {
            cur[tmp[1]] = tmp[0];
        }
    }
    
    string outTime = "23:59";
    for(auto &v:cur){
        string inTime = v.second;
        int stayTime = calcTime(inTime, outTime);
        if(carsTime.find(v.first) != carsTime.end()){
            carsTime[v.first] += stayTime;
        }
        else{
            carsTime[v.first] = stayTime;
        }
    }
    
    for(auto &v: carsTime){
        if(v.second <= fees[0]){
            carsTime[v.first] = fees[1];
        }
        else{
            if((v.second - fees[0])%fees[2] != 0){
                carsTime[v.first] = fees[1] + ((v.second - fees[0]) / fees[2] + 1) * fees[3];
            }
            else{
                carsTime[v.first] = fees[1] + ((v.second - fees[0]) / fees[2]) * fees[3];
            }
        }
    }
    
    vector<pair<string, int>> carsFee(carsTime.begin(), carsTime.end());
    sort(carsFee.begin(), carsFee.end());
    
    vector<int> answer;
    
    for(auto&v:carsFee){
        answer.push_back(v.second);
    }
    
    return answer;
}