//[골드2] 16920.확장게임 https://www.acmicpc.net/problem/16920

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#include <algorithm>
#include <queue>

int n, m, p;
int s[10] = {0};
int castlesNum[10] = {0};
char board[1001][1001];
queue<pair<int, int>> castles[10];
bool canGoNextTurn = true;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

typedef struct _node{
  int x;
  int y;
  int depth;
} Node;

void printBoard(){

  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cout<<board[i][j];
    }
    cout<<"\n";
  }

}

void getInput(){
  cin>>n>>m>>p;

  for(int i=1;i<=p;++i){
    cin>>s[i];
  }

  int player;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      cin>>board[i][j];
      if('1' <= board[i][j] && board[i][j] <='9'){
        player = board[i][j] - '1' + 1;
        castles[player].push({i, j});
        ++castlesNum[player];
      }
    }
  }

}

void BFS(int player){
  queue<Node> q;

  if(!castles[player].empty()){
    canGoNextTurn = true;
  }

  pair<int, int> tmp;
  while(!castles[player].empty()){
    tmp = castles[player].front();
    q.push({tmp.first, tmp.second, 0});
    castles[player].pop();
  }

  Node front;
  int newX, newY;
  while(!q.empty()){
    front = q.front();
    q.pop();

    if(front.depth == s[player]){
      castles[player].push({front.x, front.y});
    }

    for(int dir=0;dir<4;++dir){
      newX = front.x + dx[dir];
      newY = front.y + dy[dir];
      
      if(newX < 0 || newY < 0 || newX >= n || newY >= m)
        continue;

      if(board[newX][newY] == '.' && front.depth < s[player]){
        board[newX][newY] = board[front.x][front.y];
        ++castlesNum[player];
        q.push({newX, newY, front.depth + 1});
      }
    }

  }

}

int main(void){
  getInput();
  
  while(canGoNextTurn){
    canGoNextTurn = false;
    for(int player=1;player<=p;++player){
      BFS(player);
    }
  }

  for(int i=1;i<=p;++i){
    cout<<castlesNum[i]<<" ";
  }

}