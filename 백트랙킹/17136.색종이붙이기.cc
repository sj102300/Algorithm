//[골드2] 17136.색종이붙이기 https://www.acmicpc.net/problem/17136

#include <iostream>
#include <algorithm>
using namespace std;

int board[10][10];
int answer = 30;
int remaining[] = {0,5,5,5,5,5};

void getInput(){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            cin>>board[i][j];
        }
    }
}

bool isFulled(){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j)
            if(board[i][j] == 1)
                return false;
    }
    return true;
}

pair<int, int> findOne(){
    for(int i=0;i<10;++i){
        for(int j=0;j<10;++j){
            if(board[i][j] == 1){
                return {i, j};
            }
        }
    }
    //여기까지 안옴
    return {-1,-1};
}

bool isAttachable(pair<int, int> start, int size){
    for(int i=start.first; i<start.first+size; ++i){
        for(int j=start.second; j<start.second+size; ++j){
            if(board[i][j] == 0 || i >= 10 || j >= 10)
                return false;
        }
    }
    return true;
}

void attach(pair<int, int> start, int size){
    for(int i=start.first; i<start.first+size; ++i){
        for(int j=start.second; j<start.second+size; ++j){
            board[i][j] = 0;
        }
    }
}

void detach(pair<int, int>start, int size){
    for(int i=start.first; i<start.first+size; ++i){
        for(int j=start.second; j<start.second+size; ++j){
            board[i][j] = 1;
        }
    }
}

void btrk(int usedPapers){
    if(isFulled()){
        answer = min(answer, usedPapers);
        return;
    }

    pair<int, int> tmp = findOne();

    for(int size=5;size>=1;size--){
        if(remaining[size] > 0 && isAttachable(tmp, size)){
            attach(tmp, size);
            remaining[size]--;
            btrk(usedPapers + 1);
            remaining[size]++;
            detach(tmp, size);
        }
    }
    
}

int main(void){

    getInput();
    btrk(0);

    if(answer == 30){
        cout<<-1;
    }
    else{
        cout<<answer;
    }

}