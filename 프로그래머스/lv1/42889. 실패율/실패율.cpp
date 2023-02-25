#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Info{
    double frate;
    int idx;
    Info (double a, int b) {
        frate=a;
        idx=b;
    }
    bool operator<(const Info& a) const {
        if (frate == a.frate) return idx > a.idx;
        return frate < a.frate;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> num(N+1, 0);
    for (int i=0; i<stages.size(); i++){
        if (stages[i]!=N+1) num[stages[i]]++;
    }
    double total=stages.size();
    priority_queue<Info> pq;
    for (int i=1; i<=N; i++){
        if (num[i]==0) {
            pq.push(Info(0.0, i));
            continue;
        }
        if (total>0){
            double frate = num[i] / total;
            pq.push(Info(frate, i));
            total-=num[i];
        }
    }
    
    while (!pq.empty()){
        answer.push_back(pq.top().idx);
        pq.pop();
    }
    return answer;
}