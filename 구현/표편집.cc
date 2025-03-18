//[Lv2] 표편집 https://school.programmers.co.kr/learn/courses/30/lessons/81303?language=cpp

#include <string>
#include <vector>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    
    vector<int> prev(n), next(n);
    vector<int> isExist(n, true);
    
    for(int i=0;i<n;++i){
        prev[i] = i-1;
        next[i] = i+1;
    }
    next[n-1] = -1;
    
    vector<int> stack;
    
    int cur = k;
    
    char ch;
    int gap;
    for(auto& command : cmd){
        ch = command[0];
        if(ch == 'U'){
            gap = stoi(command.substr(2));
            for(int i=0;i<gap;++i){
                cur = prev[cur];
            }
        }
        else if(ch=='D'){
            gap = stoi(command.substr(2));
            for(int i=0;i<gap;++i){
                cur = next[cur];
            }
        }
        else if(ch=='C'){
            isExist[cur] = false;
            stack.push_back(cur);
            if(prev[cur] != -1) 
                next[prev[cur]] = next[cur];
            if(next[cur] != -1)
                prev[next[cur]] = prev[cur];
            cur = next[cur] != -1 ? next[cur] : prev[cur];
        }
        else if(ch== 'Z'){ 
            isExist[cur] = true;
            int target = stack.back();
            if(next[target] != -1) 
                prev[next[target]] = target;
            if(prev[target] != -1)
                next[prev[target]] = target;
            stack.pop_back();
        }
    }
    
    string answer(n, 'O');
    
    for(auto s:stack){
        answer[s] = 'X';
    }
    
    return answer;
}