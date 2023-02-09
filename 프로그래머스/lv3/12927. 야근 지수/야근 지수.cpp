#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for (auto i:works) pq.push(i);
    
    for (int i=0; i<n; i++){
        if (pq.empty()) break;
        int v = pq.top();
        pq.pop();
        if (v-1>0) pq.push(v-1);
    }
    while (!pq.empty()){
        int v = pq.top();
        pq.pop();
        answer += v*v;
    }
    return answer;
}