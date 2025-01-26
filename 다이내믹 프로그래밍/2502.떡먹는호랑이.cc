//[실버1] 2502.떡먹는호랑이 https://www.acmicpc.net/problem/2502

#include<iostream>
#include<vector>
using namespace std;

int d, k;
int days[31][2] = {0};

int main(void){
  cin>>d>>k;

  days[1][0] = 1;
  days[2][1] = 1;

  for(int i=3;i<=d;++i){
    days[i][0] = days[i-2][0] + days[i-1][0];
    days[i][1] = days[i-2][1] + days[i-1][1];
  }

  int a=days[d][0];
  int b=days[d][1];

  int x=1;
  int y;
  while(true){
    if((k-a*x)%b == 0 ){
      y = (k-a*x)/b;
      cout<<x<<"\n";
      cout<<y;
      return 0 ;
    }
    ++x;
  }
}