#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int g_col = 0;
bool cmp(vector<int> a, vector<int> b) 
{
    if (a[g_col-1] == b[g_col-1]) 
        return a[0] > b[0];
    return a[g_col-1] < b[g_col-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    g_col = col;
    
    // 1. 정렬
    sort(data.begin(), data.end(), cmp);
    // for (auto i : data) {
    //     cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // }
    // 2. S_i
    vector<int> s_i;
    for (int i = row_begin; i <= row_end; i++) {
        int sum = 0; 
        for (int j = 0; j < data[i-1].size(); j++) {
            sum += data[i-1][j] % i;
        }
        s_i.push_back(sum);
    }
    if (s_i.size() == 1)
        return s_i[0];
    
    answer = s_i[0];
    for (int i = 1; i < s_i.size(); i++) {
        answer = answer^s_i[i];
    }
    return answer;
}