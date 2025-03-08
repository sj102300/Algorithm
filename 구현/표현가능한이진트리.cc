//[Lv3] 표현가능한이진트리 https://school.programmers.co.kr/learn/courses/30/lessons/150367

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> answer;

int bitlimits[] = {1,3,7,15,31,63};

string getBinary(long long number){
    
    long long origin = number;
    string ret = "";
    while(number > 0){
        if(number % 2 == 0){
            ret += "0";
        }
        else{
            ret += "1";
        }
        number /= 2;
    }
    
    long long tmp = 1;
    int bitcnt = 1;
    while(origin > tmp){
        tmp = (tmp << 1);
        tmp = tmp | 1;
        bitcnt++;
    }
    
    int bitlimit = 63; // 기본값 설정
    for(int i=0;i<6;++i){
        if(bitcnt <= bitlimits[i]){
            bitlimit = bitlimits[i];
            break;
        }
    }
    
    while(ret.size() != bitlimit){
        ret += "0";
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

bool isAvail(string st, int i){
    
    if(st.size() == 1){
        return true;
    }
    if(st.size() == 3){
        if(st == "000" || st[1] == '1'){
            return true;
        }
        return false;
    }
    
    int half = (st.length()-1) / 2;
    if(st[half] == '0'){
        for(int j=0; j<st.length(); ++j){
            if(st[j] == '1')
                return false;
        }
        return true;
    }
    return isAvail(st.substr(0, half), i) && isAvail(st.substr(half+1), i);
}


vector<int> solution(vector<long long> numbers) {
    
    answer.assign(numbers.size(), 0);
    
    for(int i=0;i<numbers.size(); ++i){
        string bin = getBinary(numbers[i]);
        if(bin[bin.length() / 2] == '0')
            answer[i] = 0;
        else{
            answer[i] = isAvail(bin, i) ? 1 : 0;
        }
    }
    return answer;
}