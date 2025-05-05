//[Lv2] k진수에서소수구하기 https://school.programmers.co.kr/learn/courses/30/lessons/92335

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(long long number){
    if(number < 2) return false;
    
    for(long long i=2;i<=sqrt(number); ++i){
        if(number %i ==0)   return false;
    }
    
    return true;
}

bool hasZero(string s){
    for(auto c:s){
        if(c=='0')
            return true;
    }
    return false;
}

int solution(int n, int k) {
    
    int N = n;
    
    string changed = "";
    while(N > 0){
        int tmp = N % k;
        N /= k;
        changed += to_string(tmp);
    }
    reverse(changed.begin(), changed.end());
    
    int answer = 0;
    int left,right;
    for(int i=0;i<changed.length();++i){
        left =i;
        right=i;
        string stmp = changed.substr(i, 1);
        if(isPrime(stoll(stmp))){
            if(hasZero(stmp)){
                continue;
            }
            if(left - 1 < 0 || changed[left-1] == '0' ){
                if(right + 1 >= changed.length() || changed[right+1] == '0'){
                    ++answer;
                }
            }
        }
        for(int j=i+1;j<changed.length();++j){
            right=j;
            stmp += changed.substr(j,1);
            if(isPrime(stoll(stmp))){
                if(hasZero(stmp)){
                    continue;
                }
                if(left - 1 < 0 || changed[left-1] == '0' ){
                    if(right + 1 >= changed.length() || changed[right+1] == '0'){
                        ++answer;
                    }
                }
            }
        }
    }
    
    return answer;
}