//[골드4] 18430.무기공학 https://www.acmicpc.net/problem/18430

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bomarang[4][2][2] = {
    {{1,1},{1,0}},
    {{1,1},{0,1}},
    {{1,0},{1,1}},
    {{0,1},{1,1}},
};

pair<int, int> centerBomarang[4] = {
    {0,0}, {0,1}, {1,0}, {1,1}
};

int n, m;
int board[5][5];
int curBoard[5][5];
int centerBoard[5][5];
int answer = 0;

void getInput(){

    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>board[i][j];
            centerBoard[i][j] = 1;
        }
    }
}

bool isAvail(int startLoc, int bIdx){

    pair<int, int> startPos = {startLoc/m, startLoc%m};

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            if(startPos.first + i >= n || startPos.second + j >=m){
                return false;
            }
            if(curBoard[startPos.first + i][startPos.second + j] + bomarang[bIdx][i][j] >= 2){
                return false;
            }
        }
    }
    return true;
}

void writeBoard(int startLoc, int bIdx){
    pair<int, int> startPos = {startLoc/m, startLoc%m};

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            curBoard[startPos.first + i][startPos.second +j] += bomarang[bIdx][i][j];
        }
    }

    centerBoard[startPos.first + centerBomarang[bIdx].first][startPos.second + centerBomarang[bIdx].second] = 2;
}

void eraseBoard(int startLoc, int bIdx){
    pair<int, int> startPos = {startLoc/m, startLoc%m};

    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            curBoard[startPos.first + i][startPos.second +j] -= bomarang[bIdx][i][j];
        }
    }
    centerBoard[startPos.first + centerBomarang[bIdx].first][startPos.second + centerBomarang[bIdx].second] = 1;
}


void calc(){
    int tmp =0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            tmp += curBoard[i][j] * centerBoard[i][j] * board[i][j];
        }
    }

    // if(answer <tmp){
    //     cout<<"------curBoard---------\n";
    //     for(int i=0;i<n;++i){
    //         for(int j=0;j<m;++j){
    //             cout<<curBoard[i][j]<< " ";
    //         }cout<<endl;
    //     }
    //     cout<<"-------centerBoard--------\n";
    //     for(int i=0;i<n;++i){
    //         for(int j=0;j<m;++j){
    //             cout<<centerBoard[i][j]<< " ";
    //         }cout<<endl;
    //     }
        
    // }
    answer = max(answer, tmp);
}

void btrk(int startLoc){

    if(startLoc == n*m){
        calc();
        return;
    }

    for(int bIdx = 0; bIdx <4;++bIdx){
        if(isAvail(startLoc, bIdx)){
            writeBoard(startLoc, bIdx);
            btrk(startLoc+1);
            eraseBoard(startLoc, bIdx);
        }
    }
    btrk(startLoc+1);

}

int main(void){

    getInput();
    btrk(0);

    cout<<answer;
}