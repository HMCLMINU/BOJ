#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int e, val;
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator<(const Edge& b) const {
        return val > b.val;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, int>> m[n];
    vector<bool> ch(n);
    for (int i=0; i<costs.size(); i++){
        m[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        m[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    priority_queue<Edge> pq;
    pq.push(Edge(0, 0));
    
    while (!pq.empty()){
        Edge v=pq.top();
        pq.pop();
        int e=v.e;
        int cost=v.val;
        
        if (!ch[e]){
            answer+=cost;
            ch[e]=true;
            for (int i=0; i<m[e].size(); i++){
                pq.push(Edge(m[e][i].first, m[e][i].second));
            }
        }
        
    }
    return answer;
}