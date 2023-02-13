#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct Info{
    int st, pt;
    Info(vector<int> a){
        st=a[0];
        pt=a[1];
    }
    bool operator<(const Info& b) const {
        return pt > b.pt;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Info> pq;
    int curr_t=jobs[0][0];
    int idx=0;
    while (idx < jobs.size() || !pq.empty()){
        if (idx<jobs.size() && jobs[idx][0] <= curr_t){
            pq.push(Info(jobs[idx++]));
            continue;
        }
        
        if (!pq.empty()){
            Info p = pq.top();
            answer+= p.pt + curr_t - p.st;
            curr_t += p.pt;
            pq.pop();
        }
        else {
            curr_t = jobs[idx][0];
        }
        
    }
    
    answer /= jobs.size();
    return answer;
}