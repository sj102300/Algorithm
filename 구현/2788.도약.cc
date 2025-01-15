//[실버1] 2788.도약 https://jungol.co.kr/problem/2788

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(int a, int b, int c){
    int firstgap = b-a;
    int secondgap = c-b;
    return firstgap <= secondgap && 2 * firstgap >= secondgap;
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("/root/LigNex1/Algorithm/cpp/input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> leaves(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> leaves[i];
    
    sort(leaves.begin(), leaves.end());

    int answer = 0;
    for(int i=0;i<n-2;++i){
        for(int j=i+1;j<n-1;++j){
            for(int k=j+1;k<n;++k){
                if(isvalid(leaves[i], leaves[j], leaves[k])){
                    ++answer;
                }
            }
        }
    }
    cout<<answer;
}