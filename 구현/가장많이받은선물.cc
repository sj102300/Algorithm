//[Lv1] 가장많이받은선물 https://school.programmers.co.kr/learn/courses/30/lessons/258712

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

pair<string,string> getAtoB(string& str){
    stringstream ss(str);
    string a, b;
    ss >> a>> b;
    return {a,b};
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    unordered_map<string, int> nameToNum;
    
    int n=0;
    for(auto& f : friends){
        nameToNum[f] = n++;
    }
    
    vector<vector<int>>dp (n, vector<int>(n, 0));

    pair<string, string> AtoB;
    int A, B;
    for(auto& gift: gifts){
        AtoB = getAtoB(gift);
        A = nameToNum[AtoB.first];
        B = nameToNum[AtoB.second];
        ++dp[A][B];
    }
    
    //보낸거합, 받은거합, 선물지수
    vector<vector<int>> record(n, {0,0,0});
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            record[i][0] += dp[i][j];
            record[i][1] += dp[j][i];
        }
        record[i][2] = record[i][0] - record[i][1];
        // cout<<record[i][0] << " "<<record[i][1] <<" "<<record[i][2]<<endl;
    }
    
    vector<int> answers(n, 0);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i == j) //자기자신 건너뛰기
                continue;
            
            if(dp[i][j] > dp[j][i]){
                ++answers[i];
            }
            else if(dp[i][j] == dp[j][i]){
                //선물지수 비교
                if(record[i][2] > record[j][2]){
                    // cout<<i<<": "<<record[i][2]<< " " << record[j][2]<<endl;
                    ++answers[i];
                }
            }
        }
    }
    
    return *max_element(answers.begin(), answers.end());
}