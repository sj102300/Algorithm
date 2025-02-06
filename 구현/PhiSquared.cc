//[Lv3] PhiSquared https://softeer.ai/practice/7697

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

int n;
vector<pair<long long, long long>> phi;
vector<pair<long long, long long>> nextphi;

void getInput(){
    cin>>n;
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        phi.push_back({i, tmp});
    }
}

bool isEatable(pair<long long, long long> a, pair<long long, long long>b){
    //a가 b를 먹을 수 있는지
    return a.second >= b.second;
}

void print(vector<pair<long long, long long>>& phi){
    for(auto it= phi.begin(); it!= phi.end(); ++it){
        cout<<it->first <<" "<<it->second<< " / ";
    }
    cout<<endl;
}

int main(int argc, char** argv){

    getInput();

    long long i;
    bool canEatPrev, canEatNext;
    pair<long long, long long> lastnextphi;
    while(phi.size() > 1){
        
        if(isEatable(phi[0], phi[1])){
            nextphi.push_back({phi[0].first, phi[0].second + phi[1].second});
            i=2;
        }
        else{
            nextphi.push_back(phi[0]);
            i=1;
        }

        while(i<phi.size()-1){
            canEatPrev = isEatable(phi[i], nextphi.back());
            canEatNext = isEatable(phi[i], phi[i+1]);
            lastnextphi = nextphi.back();

            if(canEatPrev && canEatNext){
                nextphi.back() = {phi[i].first, lastnextphi.second + phi[i+1].second + phi[i].second};
                i+=2;
            }
            else if(canEatPrev && !canEatNext){
                nextphi.back() = {phi[i].first, lastnextphi.second + phi[i].second};
                ++i;
            }
            else if(canEatNext && !canEatPrev){
                nextphi.push_back({phi[i].first, phi[i+1].second + phi[i].second});
                i+=2;
            }
            else if (!canEatNext && !canEatPrev){
                nextphi.push_back(phi[i]);
                ++i;
            }
        }

        if(i == phi.size() - 1){
            lastnextphi = nextphi.back();
            canEatPrev = isEatable(phi[i], lastnextphi);
            if(canEatPrev){
                nextphi.back() = {phi[i].first, phi[i].second + lastnextphi.second};
            }
            else{
                nextphi.push_back(phi[i]);
            }
        }
        // print(phi);
        // print(nextphi);

        phi.swap(nextphi);
        nextphi.clear();
    }

    cout<<phi[0].second<<"\n"<<phi[0].first<<"\n";
}