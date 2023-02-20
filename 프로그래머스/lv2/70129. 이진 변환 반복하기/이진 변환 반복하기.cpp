#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

void dfs(int L, int r, string s, vector<int>& answer) {
    int nn=0;
    for (int i=0; i<s.size(); i++){
        int n = s[i]-'0';
        nn += n*pow(2, s.size()-1-i);
    }
    if (nn == 1) {
        answer.push_back(L);
        answer.push_back(r);
        return;
    }
    else {
        string str="";
        for (int i=0; i<s.size(); i++){
            if (s[i]=='1') str+= s[i];
            else r++;
        }
        int num = str.length();
        stack<int> stk;
        string ss="";
        while (num>0){
            stk.push(num%2);
            num = num/2;
        }
        
        while (!stk.empty()){
            ss+=to_string(stk.top());
            stk.pop();
        }
        dfs(L+1, r, ss, answer);
    }
}

vector<int> solution(string s) {
    vector<int> answer;
    dfs(0, 0, s, answer);
    return answer;
}