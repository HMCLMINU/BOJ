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
    // 현재 시간 선언
    int curr_t=jobs[0][0];
    // 현재 인덱스 선언
    int idx=0;
    while (idx < jobs.size() || !pq.empty()){
        // 작업이 남아 있으면서 현재 시간에 수행할 수 있는 작업이라면,
        // 모두 우선순위 큐 push
        if (idx<jobs.size() && jobs[idx][0] <= curr_t){
            pq.push(Info(jobs[idx++]));
            continue;
        }
        // 현재 시간에 수행할 수 있는 작업을 전부 넣었다면,
        // 소요 시간이 가장 작은 것부터 작업 처리 수행
        if (!pq.empty()){
            Info p = pq.top();
            answer+= p.pt + curr_t - p.st;
            curr_t += p.pt;
            pq.pop();
        }
        else {
            // 수행할 작업이 없는 경우 다음 작업으로 바로 넘어가기
            curr_t = jobs[idx][0];
        }
        
    }
    
    answer /= jobs.size();
    return answer;
}