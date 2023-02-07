#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, p, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> n;
    vector<vector<int>> tree(n+1);
    vector<bool> visited(n+1, false);
    vector<int> ans(n+1, 0);

    for (int i=0; i<n; i++){
        cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }

    stack<int> stk;
    stk.push(1);
    visited[1]=true; 
    while (!stk.empty()){
        int v = stk.top();
        stk.pop();

        for (int i=0; i<tree[v].size(); i++){
            if (!visited[tree[v][i]]){
                visited[tree[v][i]]=true;
                ans[tree[v][i]]=v;
                stk.push(tree[v][i]);
            }
        }
    }

    for (int i=2; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}