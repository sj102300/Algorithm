//[실버3] 1213.팰린드롬만들기 https://www.acmicpc.net/problem/1213

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> alpha((int)'Z' - (int)'A' + 1, 0);
vector<int> alphaCnt((int)'Z' - (int)'A' + 1, 0);
bool hasOdd = false;
char center;

void btrk(int pt){
  
  if(pt == (int)'Z' - (int)'A' + 1){
    if(hasOdd){
      cout<<center;
    }
    return;
  }
  
  char tmp;
  while(alpha[pt] != 0 && alphaCnt[pt] > alpha[pt] / 2){
    tmp = 'A' + pt;
    cout<<tmp;
    --alphaCnt[pt];
  }
  btrk(pt+1);
  while(alphaCnt[pt] != 0){
    tmp = 'A' + pt;
    cout<<tmp;
    --alphaCnt[pt];
  }

  return;
}

int main(void){
  string tmp;
  cin>>tmp;

  for(int i=0;i<tmp.length();++i){

    ++alpha[(int)tmp[i] - (int)'A'];
    ++alphaCnt[(int)tmp[i] - (int)'A'];
  }

  for(int i=0;i<alpha.size();++i){
    if(alpha[i] % 2 == 1){
      if(hasOdd){
        cout<< "I'm Sorry Hansoo";
        return 0;
      }
      hasOdd = true;
      center = 'A' + i;
      --alpha[i];
      --alphaCnt[i];
    }
  }

  btrk(0);  
  return 0;

}