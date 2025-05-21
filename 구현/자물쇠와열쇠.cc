//[Lv3] 자물쇠와열쇠 https://school.programmers.co.kr/learn/courses/30/lessons/60059

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, M;
void copyAndRotateKey(vector<vector<int>> &dest, vector<vector<int>> &src){
    
    dest.assign(M, vector<int>(M));
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            dest[i][j] = src[M-j-1][i];
        }
    }
    
    return;
}

bool unlockable(int x, int y, vector<vector<int>> lock, vector<vector<int>>&key){
    
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            int newX = x+i;
            int newY = y+j;
            if(newX<0||newY<0||newX>=N||newY>=N)
                continue;
            lock[newX][newY]+=key[i][j];
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(lock[i][j]!=1)
                return false;
        }
    }
    return true;
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    N = lock.size();
    M = key.size();
    vector<vector<vector<int>>> keys(4);
    keys[0].assign(M, vector<int>(M));
    for(int i=0;i<M;++i){
        for(int j=0;j<M;++j){
            keys[0][i][j] = key[i][j];
        }
    }
    
    copyAndRotateKey(keys[1], keys[0]);
    copyAndRotateKey(keys[2], keys[1]);
    copyAndRotateKey(keys[3], keys[2]);

    for(auto &a :keys){
        for(int i=-M+1; i<N;++i){
            for(int j=-M+1; j<N;++j){
                if(unlockable(i, j, lock, a)){
                    return true;
                }
            }
        }
    }

    return false;
}