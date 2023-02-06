#include <iostream>
#include <vector>

using namespace std;

int n, m, num;
int dp[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int> (n+1, 0));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> num;
            dp[i][j] = num+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    int x1, y1, x2, y2;
    for (int i=1; i<=m; i++){
        cin >> x1 >> y1 >> x2 >> y2; 
        int n = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2]+dp[x1-1][y1-1];
        cout << n << "\n"; 
    }
    return 0;
}