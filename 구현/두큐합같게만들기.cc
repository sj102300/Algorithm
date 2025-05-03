//[Lv2] 두큐합같게만들기 https://school.programmers.co.kr/learn/courses/30/lessons/118667

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    queue<int> q1;
    long long sum1 = 0;
    for(auto v:queue1){
        q1.push(v);
        sum1+=v;
    }
    long long sum2 = 0;
    queue<int> q2;
    for(auto v:queue2){
        q2.push(v);
        sum2+=v;
    }
    
    int max_operation = 2* (queue1.size() + queue2.size());
    
    int opCnt =0;
    int tmp;
    while(!q1.empty() && !q2.empty() && opCnt <= max_operation){
        if(sum1 < sum2){
            tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum2 -= tmp;
            sum1 += tmp;
        }
        else if (sum1 >sum2){
            tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
        }
        else{
            //같을때
            return opCnt;
        }
        opCnt++;
    }
    
    return -1;
}