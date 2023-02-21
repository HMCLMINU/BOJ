#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;
unordered_map<char, char> m{{'{', '}'}, {'[', ']'}, {'(', ')'}};

bool check(string& s){
    stack<char> stk;
    stk.push(s[0]);
    
    for (int i=1; i<s.size(); i++){
        char v = stk.top();
        if (stk.empty()) {
            stk.push(s[i]);
            continue;
        }
        if (m[v]!=s[i]) stk.push(s[i]);
        else stk.pop();
    }
    if (!stk.empty()) return false;
    else return true;
}

int solution(string s) {
    int answer = 0;
    
    for (int i=0; i<s.size(); i++) {
        s+=s[0];
        s.erase(s.begin());
        if (check(s)) {
            answer++;
        }
    }
    
    return answer;
}