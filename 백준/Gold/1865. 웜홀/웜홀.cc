#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int TC, N, M, W, S, E, T;

struct Node
{
    int vex;
    int eff;
    int cnt;
    Node(int a, int b, int c){
        vex=a;
        eff=b;
        cnt=c;
    }

    bool operator<(const Node& a) const {
        return eff > a.eff;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> TC;
    for (int tc=0; tc<TC; tc++){
        cin >> N >> M >> W;
        vector<vector<Node>> graph(N+1);
        for (int i=0; i<M; i++){
            cin >> S >> E >> T;
            graph[S].push_back(Node(E, T, 0));
            graph[E].push_back(Node(S, T, 0));
        }

        for (int i=0; i<W; i++){
            cin >> S >> E >> T;
            graph[S].push_back(Node(E, -T, 0));
        }

        bool flag=false;
        for (int i=1; i<=N; i++){
            priority_queue<Node> pq;
            pq.push(Node(i, 0, 0));
            vector<int> time(N+1, 2147000000);

            while (!pq.empty()){
                int vex = pq.top().vex;
                int t = pq.top().eff;
                int cnt = pq.top().cnt;
                pq.pop();
                if (time[i] < 0 || cnt>(N-1)*2) break;
                if (time[vex] < t) continue;
                

                for (int j=0; j<graph[vex].size(); j++){
                    int nvex = graph[vex][j].vex;
                    int nt = t+graph[vex][j].eff;
                    if (time[nvex] > nt){
                        time[nvex]=nt; 
                        pq.push(Node(nvex, nt, cnt+1));
                    }
                }
            }

            if (time[i] < 0){
                flag=true;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}