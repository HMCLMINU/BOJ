#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (auto i : commands) {
        int start = i[0]-1;
        int end = i[1]-1;
        int idx = i[2]-1;
        vector<int> v;
        for (int j = start; j<=end; j++) {
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[idx]);
    }
       
    return answer;
}