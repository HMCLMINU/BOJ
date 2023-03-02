#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<vector<int>> table;

vector<vector<int>> setTable(int target)
{
    vector<vector<int>> table(2);
    for (int i=1; i<=20; i++) {
        table[0].push_back(i);
        if (i*2 > 20) table[1].push_back(i*2);
        if (i*3 > 20) table[1].push_back(i*3);
    }
    table[0].push_back(50);
    return table;
}

vector<int> solution(int target) {
    vector<int> answer;
    unordered_map<int, int> hash;
    
    vector<vector<int>> dp(target+1, vector<int> (2, 0));
    for (int i=1; i<=target; i++) {
        dp[i][0]=987654321;
    }
    
    // for (int i=1; i<=20; i++){
    //     hash[i]=1;
    //     hash[i*2]=0;
    //     hash[i*3]=0;
    // }
    // hash[50]=1;
    vector<vector<int>> table = setTable(target);
    for (int i=0; i<2; i++){
        for (int j=0; j<table[i].size(); j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    for (int i=1; i<=target; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<table[j].size(); k++){
                int score = table[j][k];
                if (i-score < 0) continue;
                
                int total = dp[i-score][0]+1;
                int sum = dp[i-score][1] + 1 - j;

                if (dp[i][0] > total){
                    dp[i][0] = total;
                    dp[i][1] = sum;
                }
                else if (dp[i][0] == total){
                    dp[i][1] = max(dp[i][1], sum);
                }
            }
            
        }
        // for (auto c:hash) {
        //     int score = c.first;
        //     int sum = c.second;
        //     if (i-score < 0) continue;
        //     int total = dp[i-score][0]+1;
        //     int valid = dp[i-score][0]+sum;
        //     // 기존 던진 횟수보다 보다 작으면 던진횟수, sum 업데이트
        //     if (dp[i][0] > total) {
        //         dp[i][0] = total;
        //         dp[i][1] = valid;
        //     }
        //     // 던진 횟수는 같은 경우 던진 횟수 많으면 업데이트
        //     else if (dp[i][0] == total) {
        //         dp[i][1] = max(dp[i][1], valid);
        //     }
        // }
    }
    // for (int i=1; i<=target; i++) {
    //     cout << "i: " << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    // }
    
    answer= dp[target];

    return answer;
}