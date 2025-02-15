a//[골드5] 15686.치킨배달 https://www.acmicpc.net/problem/15686

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cstdlib>
using namespace std;

int n, m;
int answer = INT_MAX;
int board[51][51];
vector<tuple<int, int, int>> chickens;
vector<pair<int, int>> houses;

void getInput(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>board[i][j];
            if(board[i][j] == 2){
                chickens.push_back({i,j, 0});
            }
            else if(board[i][j] == 1){
                houses.push_back({i,j});
            }
        }
    }

}

int calc_chicken_dis(){
    int tmp;
    int ret = 0;
    int x, y, isselected;

    for(auto it = houses.begin(); it != houses.end(); ++it){
        tmp = INT_MAX;
        for(auto chick = chickens.begin(); chick != chickens.end(); ++chick){
            tie(x, y, isselected) = *chick;
            if(isselected){
                tmp = min(tmp, abs(it->first- x) + abs(it->second - y));
            }
        }
        ret += tmp;
    }
    return ret;
}

void btrk(int selected_num, int idx){

    if(idx == chickens.size()){
        if(selected_num == m){
            answer = min(answer, calc_chicken_dis());
        }
        return;
    }

    get<2>(chickens[idx]) = 1;
    btrk(selected_num + 1, idx+1);  //해당 집 선택할때
    get<2>(chickens[idx]) = 0;
    btrk(selected_num, idx+1);  //해당 집 ㄱ선택안할때

}

int main(void){

    getInput();

    btrk(0, 0);

    cout<<answer;

}
