//[골드5] 2608.로마숫자 https://www.acmicpc.net/problem/2608
#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>
#include <sstream>
#include <tuple>
#include <vector>

string first, second;

unordered_map<string, int> map = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};

vector<tuple<int, string>> intToStr =  {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
int getStrToInt(string &str)
{
  int answer = 0;
  string tmp = "";
  string tmpnext= "";
  for (int i = 0; i < str.length(); ++i)
  {
    tmp = str[i];
    tmpnext = str[i+1];
    if (map[tmp] >= map[tmpnext])
    {
      answer += map[tmp];
    }
    else
    {
      answer += map[tmp + tmpnext];
      ++i;
    }
  }
  return answer;
}

void getIntToStr(int num){
  stringstream ss;

  int idx = 0 ;
  while (num > 0){
    if(num >= get<0>(intToStr[idx])){
      ss<<get<1>(intToStr[idx]);
      num -= get<0>(intToStr[idx]);
    }
    else{
      idx++;
    }
  }
  
  cout<<ss.str();
}

int main(void)
{

  cin >> first >> second;

  int firstNum = getStrToInt(first);
  int secondNum = getStrToInt(second);

  int result = firstNum+secondNum;
  cout<<result<<"\n";
  getIntToStr(result);

}