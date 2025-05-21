//[Lv2] 영어끝말잇기 https://school.programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_set<string> wordset;
    
    wordset.insert(words[0]);
    string prevWord = words[0];
    
    for(int i=1;i<words.size();++i){
        if(prevWord[prevWord.size()-1] != words[i][0]
          || wordset.find(words[i]) != wordset.end()
          ){
            //졌음
            answer[0] = i%n +1;
            answer[1] = i/n +1;
            break;
        }
        else{
            prevWord = words[i];
            wordset.insert(words[i]);
        }
    }
    
    return answer;
}