//[Lv3] 2차원동전뒤집기 https://school.programmers.co.kr/learn/courses/30/lessons/131703

#include <string>
#include <vector>

using namespace std;

vector<int> rows;
vector<int> cols;
int answer = 1000;

vector<vector<int>> start;
vector<vector<int>> endBoard;

int n, m;

bool isSame(vector<vector<int>> &s, vector<vector<int>> &e){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(s[i][j] != e[i][j]){
                return false;
            }
        }
    }
    return true;
}

void copyStartBoard(vector<vector<int>> &a, vector<vector<int>> &b){
    b.assign(n, vector<int>(m, 0));
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            b[i][j] = a[i][j];
        }
    }
    return;
}

void calc(){
    
    vector<vector<int>> s;
    copyStartBoard(start, s);
    
    int cnt=0;
    
    for(int i=0;i<rows.size();++i){
        if(rows[i] == 0){   //안뒤집기
            continue;
        }
        else{   //뒤집기
            cnt++;
            for(int j=0;j<m;++j){
                s[i][j] = s[i][j] == 1 ? 0 : 1;
            }
        }
    }
    
    for(int j=0;j<cols.size(); ++j){
        if(cols[j] == 0){
            continue;
        }
        else{
            cnt++;
            for(int i=0;i<n;++i){
                s[i][j] = s[i][j] == 1 ? 0 : 1;
            }
        }
    }
    if(isSame(s,endBoard)){
        answer = min(answer, cnt);
    }
}

void btrkRows(){
    
    if(rows.size() == n){
        //계산
        calc();
        return;
    }
    
    rows.push_back(0);
    btrkRows();
    rows.pop_back();
    rows.push_back(1);
    btrkRows();
    rows.pop_back();
    
}

void copyBoard(vector<vector<int>> &beginning, vector<vector<int>> &target,
                vector<vector<int>> &s, vector<vector<int>>&e

){
    n = beginning.size();
    m = beginning[0].size();
    s.assign(n, vector<int>(m, 0));
    e.assign(n, vector<int>(m, 0));
    for(int i=0;i<n; ++i){
        for(int j=0;j<m; ++j){
            s[i][j] = beginning[i][j];
            e[i][j] = target[i][j];
        }
    }
    return;
}

void btrkCols(){
    if(cols.size() == m){
        btrkRows();
        return;
    }
    
    cols.push_back(0);
    btrkCols();
    cols.pop_back();
    cols.push_back(1);
    btrkCols();
    cols.pop_back();

}


int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    
    copyBoard(beginning, target, start, endBoard);
    btrkCols();
    
    return answer == 1000 ? -1 : answer;
}