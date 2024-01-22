#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][100001];

void bottomup(vector<vector<int>> input)
{
    dp[0][0] = input[0][0];
    dp[1][0] = input[1][0];
    dp[0][1] = input[0][1] + dp[1][0];
    dp[1][1] = input[1][1] + dp[0][0];
    int n = input[0].size();
    for (int i = 2; i < n; i++) {
        dp[0][i] = input[0][i] + max(dp[1][i-1], dp[1][i-2]);
        dp[1][i] = input[1][i] + max(dp[0][i-1], dp[0][i-2]);
    } 

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int tc, n;
    int num;
        
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n;
        vector<vector<int>> v(2, vector<int> (n, 0));
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < n; k++) {
                cin >> num;
                v[j][k] = num;
            }
        }

        bottomup(v);
    }
    return 0;
}