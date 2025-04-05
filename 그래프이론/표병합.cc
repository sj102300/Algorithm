//[Lv3] 표병합 https://school.programmers.co.kr/learn/courses/30/lessons/150366

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

void parsing(vector<string> &tmp, string& str){
    tmp.clear();
    istringstream input;
    input.str(str);
    for(string line; getline(input, line, ' ');){
        tmp.push_back(line);
    }
    return;   
}

int find(int a, vector<int> &parent){
    if(parent[a] == a)
        return a;
    
    return parent[a] = find(parent[a], parent);
}

bool join(int a, int b, vector<int> &parent){
    
    int pa = find(a, parent);
    int pb = find(b, parent);
    
    if(pa<pb){
        parent[pb] = pa;
    }
    else if(pa > pb){
        parent[pa] = pb;
    }
    else{
        return false; //이미 같은 그룹
    }
    return true;
}

vector<string> solution(vector<string> commands) {
    
    vector<string> answer;
    vector<string> tmp;
    unordered_map<string, int> rcToIdx;
    
    int n=0;
    for(int r=1;r<=50;++r){
       for(int c=1; c<=50; ++c){
           rcToIdx[to_string(r) + " " + to_string(c)] = n++;
       } 
    }
    
    vector<int> parent(n);
    for(int i=0;i<n;++i){
        parent[i] = i;
    }
    
    vector<string> gidxToValue(n, "EMPTY");
    
    for(auto &c: commands){
        parsing(tmp, c);
        
        if(tmp[0] == "UPDATE"){
            if(tmp.size() == 4){    //"UPDATE r c value"
                int idx = rcToIdx[tmp[1]+ " " +tmp[2]];
                int gidx = find(idx, parent);
                gidxToValue[gidx] = tmp[3];
            }
            else if(tmp.size() == 3){   //"UPDATE value1 value2"
                for(int i=0;i<n;++i){
                    int pid = find(i, parent);
                    if(gidxToValue[pid] == tmp[1]){
                        gidxToValue[pid] = tmp[2];
                    }
                }
            }
        }
        else if(tmp[0] == "MERGE"){  //"MERGE r1 c1 r2 c2"
            int idx1 = rcToIdx[tmp[1] + " " + tmp[2]];
            int idx2 = rcToIdx[tmp[3] + " " + tmp[4]];
            int gidx1 = find(idx1, parent);
            int gidx2 = find(idx2, parent);
            string value1 = gidxToValue[gidx1];
            string value2 = gidxToValue[gidx2];
            
            string value;
            if(value1 != "EMPTY" && value2 != "EMPTY"){
                value = value1;
            }
            else if(value1 != "EMPTY"){
                value = value1;
            }
            else if(value2 != "EMPTY"){
                value = value2;
            }
            else {
                value = "EMPTY";
            }
            
            if(join(gidx1, gidx2, parent)){
                int gidx = find(gidx1, parent);
                for(int i=0;i<n;++i){
                    int pid = find(i, parent);
                    if(pid == gidx){
                        gidxToValue[i] = "EMPTY";
                    }
                }
                gidxToValue[gidx] = value;
            }
        }
        else if(tmp[0] == "UNMERGE"){   //"UNMERGE r c"
            int idx = rcToIdx[tmp[1]+ " " + tmp[2]];
            int gidx = find(idx, parent);
            string value = gidxToValue[gidx];
            for(int i=0;i<n;++i){
                int pid = find(i, parent);
                if(pid == gidx){
                    gidxToValue[i] = "EMPTY";
                    parent[i] = i;
                }
            }
            gidxToValue[idx] = value;
        }
        else if(tmp[0] == "PRINT") {   //"PRINT r c"
            int idx = rcToIdx[tmp[1]+" " +tmp[2]];
            int gidx = find(idx, parent);
            answer.push_back(gidxToValue[gidx]);
        } 
    }
    
    return answer;
}