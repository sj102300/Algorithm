//[골드4] 17144.미세먼지안녕 https://www.acmicpc.net/problem/17144

#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>
#include <unordered_map>
using namespace std;

int r,c,t;
vector<vector<int>> board;
vector<vector<int>> diffboard;

pair<int, int> upcleaner = {-1, -1};
pair<int, int> downcleaner; //공청기는 무조건 한개임?
vector<pair<int, int>> dusts;

void getInput(){
    cin>>r>>c>>t;

    board.assign(r, vector<int>(c, 0));

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cin>>board[i][j];
            if(board[i][j] == -1){
                if(upcleaner.first == -1){
                    upcleaner = {i,j};
                }
                else{
                    downcleaner = {i,j};
                }
                board[i][j] = 0;
            }
        }
    }
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void diffuse(){
    pair<int, int>fr;
    int newX, newY;
    diffboard.assign(r, vector<int>(c, 0));

    for(auto it = dusts.begin(); it!=dusts.end(); ++it){
        fr = *it;

        int diffusedRoomNum = 0;
        for(int dir =0;dir<4;++dir){
            newX = fr.first + dx[dir];
            newY = fr.second + dy[dir];

            if(newX < 0 || newY<0||newX>=r || newY>=c || (newX == upcleaner.first && newY == upcleaner.second )|| (newX == downcleaner.first && newY == downcleaner.second))
                continue;
            
            diffboard[newX][newY] += board[fr.first][fr.second] / 5;
            diffusedRoomNum++;
            
        }
        diffboard[fr.first][fr.second] -= diffusedRoomNum * (board[fr.first][fr.second] / 5);
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            board[i][j] = diffboard[i][j] + board[i][j];
        }
    }

    diffboard.clear();
}

void getDusts(){
    dusts.clear();
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(board[i][j] != 0){
                dusts.push_back({i,j});
            }
        }
    }
}

void upclear(){
    
    for(int i=upcleaner.first-1;i>0;i--){
        board[i][0] = board[i-1][0];
    }

    for(int j=0;j<c-1;++j){
        board[0][j] = board[0][j+1];
    }

    for(int i=0;i<upcleaner.first; ++i){
        board[i][c-1] = board[i+1][c-1];
    }
    
    for(int j=c-1; j>0;j--){
        board[upcleaner.first][j] = board[upcleaner.first][j-1];
    }
}

void downclear(){

    for(int i=downcleaner.first+1; i<=r-2; ++i){
        board[i][0] = board[i+1][0];
    }

    for(int j=0;j<=c-2;++j){
        board[r-1][j] = board[r-1][j+1];
    }

    for(int i=r-1;i>=downcleaner.first+1;i--){
        board[i][c-1] = board[i-1][c-1];
    }

    for(int j=c-1;j>=1;j--){
        board[downcleaner.first][j] = board[downcleaner.first][j-1];
    }

}

void printboard(){
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<board[i][j] <<" ";
        }
        cout<<"\n";
    }
    cout<<"------------\n";
}

int main(void){
    
    getInput();

    for(int time=0;time<t;++time){
        getDusts();
        diffuse();
        upclear();
        downclear();
        // printboard();
    }
    // printboard();

    int answer=0;

    getDusts();
    for(auto it=dusts.begin();it!=dusts.end();++it){
        answer+=board[it->first][it->second];
    }
    cout<<answer;
}