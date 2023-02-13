#include<iostream>
#include<vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    int max=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (board[i-1][j-1]){
                dp[i][j]=min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j])+1;
            }
            
            if (dp[i][j]>max) max=dp[i][j];
        }
    }
    answer=max*max;
    return answer;
}