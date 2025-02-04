//[골드5] 1092.배 https://www.acmicpc.net/problem/1092

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int cranes[51];
int m;
int boxes[10001];

int getEatableBoxId(){
    for(int i=0;i<m;++i){
        if(boxes[i] != -1)
            return i;
    }
    return -1;
}

int solve(){
    
    if (cranes[0] <boxes[0])
        return -1;

    int time = 0;
    while(true){
        int cranefront = 0;
        int boxfront = getEatableBoxId();
        if(boxfront == -1)
            break;
        while(boxfront<m && cranefront<n){
            if(boxes[boxfront] == -1){
                boxfront++;
                continue;
            }
            if(cranes[cranefront] >= boxes[boxfront]){
                boxes[boxfront] = -1;
                cranefront++;
                boxfront++;
            }
            else{
                boxfront++;
            }
        }
        time++;
    }

    return time;

}

int main(void){

    cin>>n;
    for(int i=0;i<n;++i)
        cin >>cranes[i];
    cin>>m;
    for(int i=0;i<m;++i)
        cin>>boxes[i];
    
    sort(cranes, cranes + n, greater<int>());
    sort(boxes, boxes + m, greater<int>());

    cout<<solve();
}