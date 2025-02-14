//[실버1] 16113.시그널 https://www.acmicpc.net/problem/16113

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int n;
int m;
int board[5][20002];
vector<pair<int, int>> blackPart[10] = {
    {{0,0}, {0,1}, {0,2}, {1,0}, {1,2}, {2, 0}, {2,2}, {3, 0}, {3,2}, {4, 0}, {4,1}, {4,2}},
    {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}},
    {{0,0}, {0,1}, {0,2}, {1,2}, {2,0}, {2,1}, {2,2}, {3,0}, {4,0}, {4,1}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,2}, {2,0}, {2,1}, {2,2}, {3,2}, {4,0}, {4,1}, {4,2}},
    {{0,0}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}, {2,2}, {3,2}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,0}, {2,0}, {2,1}, {2,2}, {3,2}, {4,0}, {4,1}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,0}, {2,0}, {2,1}, {2,2}, {3,0}, {3,2}, {4,0}, {4,1}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,2}, {2,2}, {3,2}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}, {2,2}, {3,0}, {3,2}, {4,0}, {4,1}, {4,2}},
    {{0,0}, {0,1}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}, {2,2}, {3,2}, {4,0}, {4,1}, {4,2}},
};

vector<pair<int, int>> whitePart[10] = {
    {{1,1}, {2,1}, {3,1}},
    {{0,1}, {1,1}, {2,1}, {3,1}, {4,1}},
    {{1,0}, {1,1}, {3,1}, {3,2}},
    {{1,0}, {1,1}, {3,0}, {3,1}},
    {{0,1}, {1,1}, {3,0}, {3,1}, {4,0}, {4,1}},
    {{1,1}, {1,2}, {3,0}, {3,1}},
    {{1,1}, {1,2}, {3,1}},
    {{1,0}, {1,1}, {2,0}, {2,1}, {3,0}, {3,1}, {4,0}, {4,1}},
    {{1,1}, {3,1}},
    {{1,1}, {3,0}, {3,1}},
};

void getInput(){
    cin>>n;
    m = n / 5;
    char tmp;
    for(int i=0;i<5;++i){
        for(int j=0;j<m;++j){
            cin>>tmp;
            if(tmp == '#'){
                board[i][j] = 1;
            }
        }
    }
}

//1이면 true, 아니면 false
bool getNumber(int startX, int startY){

    int newX, newY;
    for(int i=0;i<10;++i){
        bool isAnswer = true;
        for(auto it=whitePart[i].begin(); it != whitePart[i].end(); ++it){
            newX = startX + it->first;
            newY = startY + it->second;
            if(board[newX][newY] != 0){
                isAnswer = false;
                break;
            }
        }
        
        if(isAnswer){
            for(auto it=blackPart[i].begin(); it != blackPart[i].end(); ++it){
                newX= startX + it->first;
                newY = startY + it->second;

                if(board[newX][newY] != 1){
                    isAnswer = false;
                    break;
                }
            }
        }

        if(isAnswer){
            cout<<i;
            if(i==1)
                return true;
            return false;
        }
    }

    return false;
}

int main(void){

    getInput();

    for(int i=0;i<m;i++){
        if(board[0][i] == 1){
            if(getNumber(0, i)){
                i++;
            }
            else{
                i+=2;
            }
        }
    }
}