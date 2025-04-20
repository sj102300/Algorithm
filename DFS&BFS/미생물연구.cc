//[L13] 미생물연구 https://www.codetree.ai/ko/frequent-problems/problems/microbial-research/description?introductionSetId=&bookmarkId=

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef struct _microbial{
    int x;
    int y;
    int turn;
} Microbial;

int n, q;
vector<vector<int>> board;
vector<vector<int>> newBoard;
vector<vector<Microbial>> microbialGroups;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int visited[16][16];

void getMicrobialGroup(vector<Microbial> &g, int sx, int sy, int turn){
    visited[sx][sy] = 1;
    int f=0;
    g.push_back({sx, sy, turn});

    Microbial first;
    int newX, newY;
    while(f < g.size()){
        first = g[f++];

        for(int dir=0;dir<4;++dir){
            newX = first.x + dx[dir];
            newY = first.y + dy[dir];

            if(newX <0 || newY <0 || newX >= n || newY >=n)
                continue;
            
            if(visited[newX][newY] == 0 && board[newX][newY] == turn){
                g.push_back({newX, newY, turn});
                visited[newX][newY] = 1;
            }
        }
    }

    return;
}

bool comp_microbial(vector<Microbial> &a, vector<Microbial> &b){
    if(a.size() != b.size()){
        return a.size() > b.size();
    }

    return a[0].turn < b[0].turn;
}

void deleteMicrobialGroups(){

    //쪼개진 미생물 무리는 삭제하기
    sort(microbialGroups.begin(), microbialGroups.end(), comp_microbial);

    unordered_set<int> existMicrobialGroups;
    unordered_set<int> deletedMicrobialGroups;

    for(auto &g: microbialGroups){
        if(existMicrobialGroups.find(g[0].turn) == existMicrobialGroups.end() ) {
            existMicrobialGroups.insert(g[0].turn);
        }
        else{
            deletedMicrobialGroups.insert(g[0].turn);
        }
    }

    for(auto it = microbialGroups.begin(); it!=microbialGroups.end();){
        if(deletedMicrobialGroups.find((*it)[0].turn) !=deletedMicrobialGroups.end() ){
            it = microbialGroups.erase(it);
        }
        else{
            ++it;
        }
    }
}

void makeMicrobialGroups(){
    microbialGroups.clear();
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(visited[i][j] == 0 && board[i][j] != 0){
                microbialGroups.push_back({});
                getMicrobialGroup(microbialGroups[microbialGroups.size() - 1], i, j, board[i][j]);
            }        
        }
    }

    return;

}

bool comp_xy(Microbial &a, Microbial&b){
    if(a.x != b.x){
        return a.x<b.x;
    }
    return a.y<b.y;
}

bool isAvail(int sx, int sy, vector<Microbial> &g){
    int offsetX = g[0].x-sx;
    int offsetY = g[0].y-sy;

    int newX, newY;
    for(auto &m:g){
        newX = m.x - offsetX;
        newY = m.y - offsetY;

        if(newX <0 || newY<0 || newX >=n || newY>=n)
            return false;

        if(newBoard[newX][newY] != 0){
            return false;
        }
    }
    return true;
}

void mark(int sx, int sy, vector<Microbial> &g){
    
    int offsetX = g[0].x - sx;
    int offsetY = g[0].y - sy;
    int turn = g[0].turn;

    for(auto &m:g){
        newBoard[m.x-offsetX][m.y - offsetY] = turn;
    }
}

bool relocationOneGroup(vector<Microbial> &g){

    sort(g.begin(), g.end(), comp_xy);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(isAvail(i, j, g)){
                mark(i, j, g);
                return true;
            }
        }
    }
    return false;

}

void relocation(){

    newBoard.clear();
    newBoard.assign(n, vector<int>(n, 0));
    
    for(auto &g: microbialGroups){
        relocationOneGroup(g);
    }

    board.swap(newBoard);
    return;
}

bool isAdj(vector<Microbial>&g1, vector<Microbial>&g2){
    
    int newX, newY;
    for(auto& m:g1){
        
        for(int dir=0;dir<4;++dir){
            newX = m.x + dx[dir];
            newY = m.y + dy[dir];

            if(newX <0|| newY<0|| newX>=n|| newY>=n)
                continue;

            for(auto &m2:g2){
                if(m2.x == newX && m2.y == newY)
                    return true;
            }
        }
    }
    return false;
}

int record(){

    int sum =0;
    makeMicrobialGroups();

    for(auto it=microbialGroups.begin(); it!=microbialGroups.end() - 1; ++it){
        for(auto it2= it+1; it2 !=microbialGroups.end(); ++it2){
            if(isAdj(*it, *it2)){
                sum += it->size() * it2->size();
            }
        }
    }
    return sum;

}

void printBoard(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<board[i][j]<<" ";
        }cout<<endl;
    }
}

int main(void){

    cin>>n>>q;
    board.assign(n, vector<int>(n, 0));

    int r1, r2, c1, c2;
    for(int turn=1;turn<=q; ++turn){
        cin>>r1>>c1>>r2>>c2;

        //미생물 붙이기
        for(int i=r1;i<r2;++i){
            for(int j=c1;j<c2;++j){
                board[i][j] = turn;
            }
        }
        
        //미생물 무리 그룹 만들기
        makeMicrobialGroups();
        //쪼개진거 없애기
        deleteMicrobialGroups();
        //재배치
        relocation();
        //기록
        cout<<record()<<"\n";
        // printBoard();
    }
}