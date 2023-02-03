#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, parent, child, weight;

struct Node
{
    int vex, weight;
    Node(int a, int b){
        vex=a;
        weight=b;
    }
};

pair<int, int> dfs(vector<vector<Node>>& g, int st)
{
    stack<int> stk;
    vector<int> dist(n+1, -1);
    stk.push(st);   
    dist[st]=0;
    
    while (!stk.empty()){
        int v = stk.top();
        stk.pop();
        
        for (int i=0; i<g[v].size(); i++){
            int nv = g[v][i].vex;
            int nc = g[v][i].weight;
            if (dist[nv]==-1){
                dist[nv] = dist[v]+nc;
                stk.push(nv);
            }
        }
    }
    int max_idx=0;
    int max=0;
    for (int i=1; i<dist.size(); i++){
        if (dist[i]>max){
            max = dist[i];
            max_idx=i;
        }
    }

    return {max_idx, max};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> n;
    vector<vector<Node>> graph(n+1);
    for (int i=0; i<n; i++){
        cin >> parent >> child >> weight;
        graph[parent].push_back(Node(child, weight));
        graph[child].push_back(Node(parent, weight));
    }

    pair<int, int> v;
    v = dfs(graph, 1);
    v = dfs(graph, v.first);
    cout << v.second << endl;
    return 0;
}