//[Lv2] 양궁대회 https://school.programmers.co.kr/learn/courses/30/lessons/92342

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> ryan(11, 0);
vector<int> answer(1, -1);
int answerScoreGap = 0;
int N;

int calcScore(vector<int>& ryan, vector<int>&apeach){
    int ryanScore=0;
    int apeachScore = 0;
    for(int i=0;i<ryan.size(); ++i){
        if(ryan[i] > apeach[i]){
            ryanScore += 10 - i;
        }
        else {
            if(apeach[i] != 0)
                apeachScore += 10 - i;
        }
    }
    
    return ryanScore - apeachScore;
}

void setAnswer(vector<int>&ryan){
    answer.clear();
    for(auto it = ryan.begin();it!=ryan.end(); ++it){
        answer.push_back(*it);
        cout<<*it<<" ";
    }
    cout<<endl;
    return;
}

bool compareAnswer(vector<int>&ryan){
    for(int i=10;i>=0;--i){
        if(ryan[i] > answer[i])
            return true;
        else if(ryan[i] < answer[i])
            return false;
    }
    
    //여기 오면 안됨
    cout<<"이상해"<<endl;
    return false;
}

void btrk(int usedArrow, int i, vector<int> &info){
    if(usedArrow > N){
        return; //early exit
    }
    if(i == 11){  //끝까지 옴
        if(usedArrow <= N) {   //정답 조건
            if(usedArrow < N){
                ryan[10] = N - usedArrow;
            }
            int scoreGap = calcScore(ryan, info);
            if(scoreGap <= 0)
                return; //어피치 승
            if(answerScoreGap < scoreGap){
                answerScoreGap = scoreGap;
                setAnswer(ryan);
            }
            else if(answerScoreGap == scoreGap){
                if(compareAnswer(ryan))
                    setAnswer(ryan);
            }
        }
        return;
    }
    
    ryan[i] = info[i] + 1;
    btrk(usedArrow + ryan[i], i+1, info);
    ryan[i] = 0;
    btrk(usedArrow, i+1, info);
    return;
}

vector<int> solution(int n, vector<int> info) {
    
    N = n;
    btrk(0, 0, info);
    
    return answer;
}