#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

void dfs(map<string, int>& map, int size, int idx, string s, string res)
{
    if (res.size() == size) {
        sort(res.begin(), res.end());
        map[res]++;
        return;
    }
    
    for (int i = idx; i < s.size(); i++) {
        res += s[i];
        dfs(map, size, i+1, s, res);
        res.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    // 모든 조합 탐색
    for (auto i : course) {
        map<string, int> m;
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].size() >= i) {
                // 조합
                string res;
                dfs(m, i, 0, orders[j], res);
            }
        }
        vector<pair<string, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        int max = 0;
        for (auto cs : v) {
            if (cs.second >= 2 && cs.second >= max) {
                answer.push_back(cs.first);
                max = cs.second;
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}