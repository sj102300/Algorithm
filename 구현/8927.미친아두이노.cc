//[골드3] 8927.미친아두이노 https://www.acmicpc.net/problem/8972

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int R, C;
vector<vector<char>> board;
vector<int> moving;
int dxdy[9][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
pair<int, int> Jongsu;
vector<pair<int, int>> arduinos;    
vector<pair<int, int>> tmp;


void getInput(void)
{

    cin >> R >> C;

    board.assign(R, vector<char>(C, '\0'));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
        }
    }

    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.length(); ++i)
    {
        moving.push_back(tmp[i] - '1');
    }

    return;
}

void getPositions(void)
{

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == 'I')
                Jongsu = {i, j};
            else if (board[i][j] == 'R')
                arduinos.push_back({i, j});
        }
    }
    return;
}

int getMovingDirection(pair<int, int> arduino, pair<int, int> Jongsu)
{
    int distance, minDir = 10000;
    int dirIdx= 0;
    int newX, newY;
    for(int i=0;i<9;++i){
        newX = arduino.first + dxdy[i][0];
        newY = arduino.second + dxdy[i][1];
        distance = abs(newX - Jongsu.first) + abs(newY - Jongsu.second);
        if (distance < minDir){
            dirIdx = i;
            minDir = distance;
        }
    }
    return dirIdx;
}

void moveJongsu(int dir)
{
    int newX, newY;

    newX = Jongsu.first + dxdy[dir][0];
    newY = Jongsu.second + dxdy[dir][1];

    board[Jongsu.first][Jongsu.second] = '.';
    board[newX][newY] = 'I';
    Jongsu = {newX, newY};

    return;
}

bool moveArduino(int dir, int arduinoIdx){
    int newX, newY;
    newX = arduinos[arduinoIdx].first + dxdy[dir][0];
    newY = arduinos[arduinoIdx].second + dxdy[dir][1];

    if(newX == Jongsu.first && newY == Jongsu.second){
        return true;
    }

    board[arduinos[arduinoIdx].first][arduinos[arduinoIdx].second] = '.';
    arduinos[arduinoIdx] = {newX, newY};

    return false;
}

bool moveArduinos(){
    int dir;
    for(int i=0;i<arduinos.size();++i){
        dir = getMovingDirection(arduinos[i], Jongsu);
        if(moveArduino(dir, i)){
            return true;
        }
    }
    return false;
}

void getRemainArduinos(){

    unordered_map<string, int> remaining;
    string str;
    for(int i=0;i<arduinos.size();++i){
        str = to_string(arduinos[i].first) + " " + to_string(arduinos[i].second);
        if (remaining.count(str)){
            remaining[str] += 1;
        }
        else{
            remaining[str] = 1;
        }
    }

    tmp.clear();
    int x,y;
    for(auto it=remaining.begin(); it!=remaining.end(); ++it){
        if (it->second == 1){
            stringstream ss(it->first);
            ss>>x>>y;
            tmp.push_back({x,y});
        }
    }
    arduinos.swap(tmp);
    return;
}

void writeRemainArduinos(){
    
    int tmp = arduinos.size();
    for(int i=0;i<arduinos.size();++i){
        board[arduinos[i].first][arduinos[i].second] = 'R';
    }
    return;
}

void printBoard(){
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
    return;
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("/root/LigNex1/Algorithm/cpp/input.txt", "r", stdin);

    getInput();
    getPositions();

    int newX, newY;
    bool isGameEnded = false;
    for (int step = 0; step < moving.size(); ++step)
    {
        moveJongsu(moving[step]);
        if(moveArduinos()){
            cout<<"kraj "<<step+1;
            isGameEnded = true;
            break;
        };
        getRemainArduinos();
        writeRemainArduinos();
    }
    if (!isGameEnded)
        printBoard();

}