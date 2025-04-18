//[브론즈3] 17284.VendingMaching https://www.acmicpc.net/problem/17284

#include <string>
#include <iostream>
using namespace std;

int money = 5000;
int arr[4] = {0, 500, 800, 1000};

int main(void){
    
    // freopen("/root/LigNex1/Algorithm/cpp/input.txt", "r", stdin);
    string str;
    while(getline(cin, str, ' ')){
        money -= arr[stoi(str)];
    }
    cout<<money;
}