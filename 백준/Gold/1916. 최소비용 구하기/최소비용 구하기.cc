#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B, C;

struct Node
{
    int vex, dist;
    Node(int a, int b){ 
        vex=a;
        dist=b;
    }
    bool operator<(const Node& a) const {
        return dist > a.dist;
    }
};

void dijkstra(vector<vector<Node>>& graph, int st, vector<int>& dist)
{
    priority_queue<Node> pq;
    pq.push(Node(st, 0));
    dist[st]=0;

    while (!pq.empty()){
        int node = pq.top().vex;
        int cost = pq.top().dist;
        pq.pop();
        if (dist[node]<cost) continue;

        for (int i=0; i<graph[node].size(); i++){
            int nnode = graph[node][i].vex;
            int ncost = cost + graph[node][i].dist;
            if (dist[nnode] > ncost){
                dist[nnode]=ncost;
                pq.push(Node(nnode, ncost));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> M;
    
    vector<vector<Node>> graph(N+1);
    for (int i=0; i<M; i++){
        cin >> A >> B >> C;
        graph[A].push_back(Node(B,C));
    }

    cin >> A >> B;
    vector<int> dist(N+1, 2147000000);
    dijkstra(graph, A, dist);
    cout << dist[B] << endl;
    return 0;
}