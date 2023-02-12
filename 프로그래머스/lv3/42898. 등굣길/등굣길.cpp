#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    vector<vector<int>> map(n+1, vector<int> (m+1, 0));
    for (int i=0; i<puddles.size(); i++){
        int col = puddles[i][0];
        int row = puddles[i][1];
        map[row][col]=-1;
    }
    dp[1][1]=1;
    for (int r=1; r<=n; r++){
        for (int c=1; c<=m; c++){
            if (dp[r][c]) continue;
            if (map[r][c]==-1) continue;
            
            dp[r][c] = (dp[r-1][c]+dp[r][c-1]) % 1000000007;
        }
    }
    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    answer = dp[n][m];
    return answer;
}