//[골드3] 16637.괄호추가하기 https://www.acmicpc.net/problem/16637

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>  // LLONG_MIN을 사용하기 위해 필요
#include <vector>

using namespace std;

int n;
vector<long long> answers;  //디버깅용
long long answer = LLONG_MIN;

long long calc(long long a, char op, long long b){
    if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else if(op == '*')
        return a*b;
    else
        cout<<"뭐냐 넌";
    return -1;
}

void printAnswers(){
    for(auto it=answers.begin();it!=answers.end();++it){
        cout<<*it <<" ";
    }
    cout<<"\n";
}

void btrk(long long initValue, string remaining){
    if(remaining.length() == 0){
        answer = max(answer, initValue);
        answers.push_back(initValue);
        return;
    }

    char op = remaining[0];
    long long firstInt = remaining[1] - '0';
    
    //괄호 안칠때
    btrk(calc(initValue, op, firstInt), remaining.substr(2));

    //괄호 칠때
    if(remaining.length() > 2){
        char op2 = remaining[2];
        long long secondInt = remaining[3] - '0';
        long long secondValue = calc(firstInt, op2, secondInt);
        btrk(calc(initValue, op, secondValue), remaining.substr(4));
    }
}

int main(void){

    cin>>n;
    string str;
    cin>>str;

    long long initValue = str[0] - '0';

    btrk(initValue, str.substr(1));

    // printAnswers();
    cout<<answer;

}