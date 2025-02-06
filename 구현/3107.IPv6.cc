//[골드5] 3107.IPv6 https://www.acmicpc.net/problem/3107

#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
#include <vector>
#include <sstream>

int main(void){

    string answer[8];

    for(int i=0;i<8;++i){
        answer[i] = "0000";
    }

    vector<string> groups;

    string origin;
    cin>>origin;

    stringstream ss(origin);
    char delim = ':';
    string token;
    while(getline(ss, token, delim)){
        groups.push_back(token);
    }

    for(int i=0;i<8;++i){
        if(groups[i] == "")
            break;
        answer[i] = groups[i];
    }

    int tmp = 7;
    for(int i=groups.size()-1;i>=0;--i){
        if(groups[i] == "")
            break;
        answer[tmp--] = groups[i];
    }

    for(int i=0;i<8;++i){
        if(answer[i].length() <4){
            string tmp2 = "";
            for(int j=0; j < 4 - answer[i].length(); ++j){
                tmp2 += "0";
            }
            tmp2 += answer[i];
            answer[i] = tmp2;
        }
    }

    for(int i=0;i<7;++i){
        cout<<answer[i]<<":";
    }
    cout<<answer[7];

}