#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> v; 
map<vector<int>, int> h;

void permutation(vector<int> permute, vector<int> visited, int n, int idx)
{
    permute.push_back(v[idx]);
    visited[idx] = 1;
    // end condition
    if (permute.size() == n) {
        if (!h[permute]) {
            for (auto i : permute) {
                cout << i << " ";
            }
            cout << endl;
            h[permute] = 1;
        }
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (visited[i] == 0)
            permutation(permute, visited, n, i);
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int num;
    vector<int> visited(n, 0); 

    for (int i = 0; i < n; i++) {
        cin >> num; 
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    vector<int> p;
    for (int i = 0; i < v.size(); i++) {
        permutation(p, visited, m, i);
        p.clear();
        for (int k = 0; k < visited.size(); k++) {
            visited[k] = 0;
        }
    }
    
    return 0;
}