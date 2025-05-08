//[Lv2] 비밀코드해독 https://school.programmers.co.kr/learn/courses/30/lessons/388352

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> curCode;
int N, M;
int answer = 0;

vector<vector<int>> Q;
vector<int> Ans;

bool isAvail(){
    for(int i=0;i<M;++i){
        int cnt=0;
        for(int a=0;a<5;++a){
            for(int b=0;b<5;++b){
                if(Q[i][a] == curCode[b]){
                    ++cnt;
                }
            }
        }
        if(cnt != Ans[i]){
            return false;
        }
    }
    
    return true;
}

void btrk(int sidx, int idx){
    if(idx == 5){
        //계산
        if(isAvail()){
            ++answer;            
        }
        return;
    }
    
    for(int i=sidx; i<=N; ++i){
        curCode.push_back(i);
        btrk(i+1, idx+1);
        curCode.pop_back();
    }
}

void copyBoard(vector<vector<int>> &q, vector<int> &ans){
    Q.assign(M, vector<int>(5, 0));
    Ans.assign(M, 0);
    
    for(int i=0;i<M;++i){
        for(int j=0;j<5;++j){
            Q[i][j] = q[i][j];
        }
        Ans[i] = ans[i];
    }
    return;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    N = n;
    M = q.size();
    copyBoard(q, ans);
    btrk(1,0);
    
    return answer;
}