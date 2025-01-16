//[골드5] 2447.별찍기-10 https://www.acmicpc.net/problem/2447
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<char>> board;
int n;

void copyBoard(pair<int, int>destS, int size){

    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            board[destS.first+i][destS.second+j] = board[i][j];
        }
    }
    return;
}

void writeEmpty(pair<int, int>destS, int size){
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j)
            board[destS.first + i][destS.second + j] = ' ';
    return;
}

void btrk(int i){
    if(i==3){
        return;
    }

    int gap = i/3;

    if(board[gap-1][gap-1] == '\0'){
        btrk(gap);
    }

    copyBoard({0, gap}, gap);
    copyBoard({0, 2*gap}, gap);
    copyBoard({gap, 0}, gap);
    writeEmpty({gap, gap}, gap);
    copyBoard({gap, 2*gap}, gap);
    copyBoard({2*gap, 0}, gap);
    copyBoard({2*gap, gap}, gap);
    copyBoard({2*gap, 2*gap}, gap);

    return;
}

void printBoard(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
    return;
}

int main(void){

    cin>>n;

    board.assign(n, vector<char>(n, '\0'));

    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            board[i][j] = '*';
    board[1][1] = ' ';

    btrk(n);
    
    printBoard();
}