#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    int vex;
    int intensity;
    Node (int a, int b) {
        vex=a;
        intensity=b;
    }
    bool operator<(const Node& b) const {
        return intensity > b.intensity;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<pair<int, int>> graph[n+1];
    vector<int> isSummit(n+1, 0);
    vector<int> intensity(n+1, 987654321);

    for (auto i : summits) isSummit[i]=1;
    for (auto p : paths) {
        graph[p[0]].push_back({p[1], p[2]});
        graph[p[1]].push_back({p[0], p[2]});
    }
    
    priority_queue<Node> pq;
    for (int i=0; i<gates.size(); i++) {
        pq.push(Node(gates[i], 0));
        intensity[gates[i]] = 0;
    }
    
    while (!pq.empty()) {
        int from = pq.top().vex;
        int cost = pq.top().intensity;
        pq.pop();
        // // 최소 힙에서 나온 값이 현재보다 큰 경우
        // if (cost > intensity[from]) continue;
        if (isSummit[from]) continue;
        
        for (auto next : graph[from]) {
            int to = next.first;
            int ncost = next.second;
            // intensity 는 단조 증가, 현재와 다음 값을 비교해서 더 큰 값을 to에 넣으면 됨
            if (intensity[to] > max(intensity[from], ncost)) {
                intensity[to] = max(intensity[from], ncost);
                pq.push(Node(to, intensity[to]));
            }
        }
    }
    
    int min_intensity=987654321;
    int idx=0;
    for (int i=1; i<intensity.size(); i++) {
        if (isSummit[i]) {
            if (min_intensity > intensity[i]) {
                min_intensity = intensity[i];
                idx = i;
            }
        }
    }
    
    return {idx, min_intensity};
}