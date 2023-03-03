#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> hash;
    string num="";
    for (int i=0; i<s.size(); i++) {
        if (isdigit(s[i])) {
            num+=s[i];
        }
        else {
            if (num.size()>0) {
                hash[stoi(num)]++;
                num="";
            }
        }
    }
    vector<pair<int, int>> v(hash.begin(), hash.end());
    sort(v.begin(), v.end(), cmp);
    for (auto i:v) {
        if (i.second>0) answer.push_back(i.first);
    }
    return answer;
}