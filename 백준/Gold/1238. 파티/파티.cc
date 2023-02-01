#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X, a, b, t;

struct Node{
    int vex;
    int time;
    Node(int a, int b){
        vex=a;
        time=b;
    }
    bool operator<(const Node &b) const {
        return time > b.time;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> X;
    vector<vector<Node>> graph(N+1);
    vector<vector<int>> dist(N+1, vector<int> (N+1, 2147000000));
    int ans=0;
    for (int i=0; i<M; i++){
        cin >> a >> b >> t;
        graph[a].push_back(Node(b, t));
    }

    for (int i=1; i<=N; i++){
        priority_queue<Node> pq;
        pq.push(Node(i, 0));
        dist[i][i]=0;
        while (!pq.empty()){
            int node = pq.top().vex;
            int time = pq.top().time;
            pq.pop();

            if (time > dist[i][node]) continue; 
            for (int j=0; j<graph[node].size(); j++){
                int nnode = graph[node][j].vex;
                int cost = time + graph[node][j].time;
                if (dist[i][nnode] > cost){
                    dist[i][nnode] = cost;
                    pq.push(Node(nnode, cost));
                }
            }
        }
    }

    for (int i=1; i<=N; i++){
        // cout << dist[i][X] << " " << dist[X][i] << endl;
        if (dist[i][X]+dist[X][i]>ans)
            ans=dist[i][X]+dist[X][i];
    }
    cout << ans << endl;
    return 0;
}