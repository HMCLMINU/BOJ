#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for (int i=0; i<triangle.size()-1; i++){
        for (int j=0; j<triangle[i].size(); j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+triangle[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+triangle[i+1][j+1]);
        }
    }
    int h = triangle.size();
    for (int i=0; i<h; i++){
        if (dp[h-1][i] > answer) answer = dp[h-1][i];
    }
    return answer;
}