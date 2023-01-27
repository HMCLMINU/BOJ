#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    
    // Linked list
    for (int i=0; i<M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // Save 케빈베이컨
    vector<int> ans(N+1, 0);
    for (int i=1; i<=N; i++){
        // BFS for every node
        vector<pair<int, int>> ch(N+1);
        queue<int> q;
        q.push(i);
        ch[i].first=1;
        ch[i].second=0;

        while (!q.empty()){
            int n = q.front();
            q.pop();
            
            for (int j=0; j<graph[n].size(); j++){
                if (!ch[graph[n][j]].first){
                    ch[graph[n][j]].first = 1;
                    ch[graph[n][j]].second = ch[n].second+1;
                    q.push(graph[n][j]);
                }
            }
        }
        
        for (auto& c:ch) {
            ans[i] += c.second;
        }
    }
    // Find answer
    int min=2147000000, res=0;
    for (int i=1; i<ans.size(); i++){
        if (ans[i] < min){
            min = ans[i];
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}