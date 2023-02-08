#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int r[3]={2, 1, 3};
int d[3]={3, 2, 4};

long long solution(vector<int> weights) {
    long long answer = 0;
    
    set<int> w;
    map<int, int> wc;
    
    for (auto& i:weights){
        w.insert(i);
        wc[i]++;
    }
    
    for (auto& weight : w){
        long long wSize=wc[weight];
        answer += wSize*(wSize-1)/2;
        
        for (int i=0; i<3; i++){
            if (weight*r[i]%d[i]) continue;
            
            int calc = weight*r[i]/d[i];
            // cout << weight << " " << calc << endl;
            long long num = wc[calc];
            answer += wSize * num;
        }
    }
    return answer;
}