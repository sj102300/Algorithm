//[Lv1] 택배상자꺼내기 https://school.programmers.co.kr/learn/courses/30/lessons/389478

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int maxHeight = n % w == 0 ? n/w : n/w + 1;
    
    vector<vector<int>> board(maxHeight, vector<int>(w, 0));
    
    pair<int, int> target;
    
    int tmp = 0;
    bool isEnd = false;
    for(int i=0; i<maxHeight; ++i){
        if(i%2==0){
            //오른쪽으로 증가
            for(int j=0;j<w;++j){
                board[i][j] = ++tmp;
                if(tmp == n){
                    isEnd = true;
                    break;
                }
            }
        }
        else{
            //왼쪽으로 증가
            for(int j=w-1; j>=0; --j){
                board[i][j] = ++tmp;
                if(tmp == n){
                    isEnd = true;
                    break;
                }
            }
        }
        if(isEnd){
            break;
        }
    }
    
    for(int i=0;i<maxHeight;++i){
        for(int j=0;j<w;++j){
            if(board[i][j] == num){
                target={i,j};
                break;
            }
        }
    }
    cout<<target.first<<" "<<target.second<<endl;
    
    int answer = 1;
    for(int i=maxHeight-1;i>=0;--i){
        if(board[i][target.second] == 0){
            continue;
        }
        if(board[i][target.second] == num){
            break;
        }
        answer++;
    }
    
    return answer;
}