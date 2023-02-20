#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    stk.push(s[0]);
    
    for (int i=1; i<s.size(); i++){
        if (!stk.empty()){
            if (stk.top() != s[i]) stk.push(s[i]);
            else stk.pop();
        }
        else stk.push(s[i]);
    }
    if (stk.empty()) return 1;
    else return 0;

}