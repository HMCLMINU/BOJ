#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[9];
int ch[9];
void dfs(vector<int> v, int L)
{
    if (L==M){
        for (int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    } 
    else{ 
        for (int i=1; i<=N; i++){
            if (ch[i]) continue;
            ch[i]=1;
            arr[L]=v[i];
            dfs(v, L+1);
            ch[i]=0;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    vector<int> v(N+1, 0);
    for (int i=1; i<=N; i++){
        cin >> v[i];
    }   
    sort(v.begin(), v.end());
    dfs(v, 0);
    return 0;
}