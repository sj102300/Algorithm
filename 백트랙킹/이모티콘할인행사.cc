//[Lv2] 이모티콘할인행사 https://school.programmers.co.kr/learn/courses/30/lessons/150368

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> answer = {0,0};

void calc(vector<int>& sales, vector<int> &emoticons, vector<vector<int>>& users){
    
    int join = 0;
    int salesAmount = 0;
    
    for(auto user = users.begin(); user!=users.end(); ++user){
        int rate = (*user)[0];
        int price = (*user)[1];
        int totalPrice = 0;
        
        for(int i=0;i<sales.size();++i){
            if(sales[i] >= rate){
                int emoticonPrice = emoticons[i] / 100 * (100 - sales[i]) ;
                totalPrice += emoticonPrice;
            }
        }
        
        if(totalPrice >= price){
            join++;
        }
        else{
            salesAmount += totalPrice;
        }
    }
    
    if(join > answer[0]){
        answer = {join, salesAmount};
    }
    else if(join == answer[0] && salesAmount > answer[1]){
        answer = {join, salesAmount};
    }
    
}

void btrk(vector<int> &sales, vector<int>& emoticons, vector<vector<int>>& users){
    if(sales.size() == emoticons.size()){
        calc(sales, emoticons, users);
        return;
    }
        
    sales.push_back(10);
    btrk(sales, emoticons, users);
    sales.pop_back();
    
    sales.push_back(20);
    btrk(sales, emoticons, users);
    sales.pop_back();
    
    sales.push_back(30);
    btrk(sales, emoticons, users);
    sales.pop_back();
    
    sales.push_back(40);
    btrk(sales, emoticons, users);
    sales.pop_back();
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> sales;
    
    btrk(sales, emoticons, users);
        
    return answer;
}