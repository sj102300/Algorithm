//[Lv2] 메뉴리뉴얼 https://school.programmers.co.kr/learn/courses/30/lessons/72411

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> answer;
vector<string> alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

int maxCourseLen;

vector<pair<string, int>> menusToOrdersNum;
unordered_map<int, int> courseNumToMenus;

vector<bool> menus(26, false);

bool checkCourseLen(vector<int>&course, int num){
    for(auto it = course.begin();it!= course.end();++it){
        if(*it == num){
            return true;
        }
    }
    return false;
}

bool checkAnswer(vector<string> &orders){
    
    string str = "";
    
    for(int i=0;i<26;++i){
        if(menus[i]){
            str+= alphabet[i];
        }
    } //비교할 문자열 만들기
    
    // cout<<"str:"<<str<<endl;
    
    int times =0;
    bool hasAlphabet;
    bool isAvailOrder;
    
    for(auto order:orders){
        isAvailOrder = true;
        for(int i=0;i<str.length(); ++i){
            hasAlphabet = false;
            for(int j=0; j<order.length(); ++j){
                if(str[i] == order[j]){
                    hasAlphabet = true;
                    break;
                }
            }
            if(!hasAlphabet){
                isAvailOrder = false;
                break;
            }
        }
        
        if(isAvailOrder){
            ++times;
        }
    }
    
    if(times>=2){
        menusToOrdersNum.push_back({str, times});
        // cout<<str<<": "<<times<<endl;
        return true;
    }
    
    return false;
    
}

void btrk(int cur, int num, vector<int>& course, vector<string> &orders){
    if(num > maxCourseLen){
        return;     //개수초과
    }
    if(cur == 26){
        if(checkCourseLen(course, num)){
            checkAnswer(orders);
        }
        return;
    }
    
    btrk(cur+1, num, course, orders);       //선택안할때
        
    menus[cur] = true;
    btrk(cur+1, num+1, course, orders);     //선택할때
    menus[cur] = false;
    return;
}

bool comp(pair<string, int> a, pair<string, int> b){
    return b.second < a.second;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    maxCourseLen = course.at(course.size()-1);
    
    btrk(0,0,course, orders);
    
    sort(menusToOrdersNum.begin(), menusToOrdersNum.end(), comp);
    
    for(auto& v: menusToOrdersNum){
        if(courseNumToMenus.find(v.first.length()) == courseNumToMenus.end()){
            courseNumToMenus[v.first.length()] = v.second;
            answer.push_back(v.first);
        }
        else{
            if(courseNumToMenus[v.first.length()] == v.second){
                answer.push_back(v.first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}