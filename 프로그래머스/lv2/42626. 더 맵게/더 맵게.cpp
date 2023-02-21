#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& i:scoville) pq.push(i);
    
    while (true){
        int first = pq.top();
        if (first >= K) break;
        pq.pop();
        if (!pq.empty()){
            int second = pq.top();
            pq.pop();
            pq.push(first+second*2);
            answer++;
        }
        else return -1;         
    }
    return answer;
}