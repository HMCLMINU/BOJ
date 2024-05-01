#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    stk.push(s[0]);
    for (int i=1; i<s.size(); i++){
        if (s[i]=='(') stk.push(s[i]);
        else{
            if (!stk.empty()) stk.pop();
            else return false;
        }
    }
    
    if (stk.empty()) return true;
    else return false;
}