#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size()-k;
    string s;
    stack<char> stk;
    stk.push(number[0]);
    int idx = 1;
    /*
        stack top과 비교
        현재가 더 클 경우 pop & k-- & 현재 수 push
        현재가 더 작거나 같은 경우 push
        k가 0이 될때 종료 및 리버스 출력
    */
    while (idx < number.size()) {
        char c = stk.top();
        if (number[idx] > c && k > 0) {
            stk.pop();
            // cout << "pop: " << c << endl;
            k--;
        }
        else {
            stk.push(number[idx]);
            // cout << "push: " << number[idx] << endl;
            idx++;
        }
        
        if (stk.empty()) {
            stk.push(number[idx]);
            // cout << "empty push: " << number[idx] << endl;
            idx++;
        }
    }
    
    while (!stk.empty()) {
        s += stk.top();
        stk.pop();
    }
    reverse(s.begin(), s.end());
    // cout << "this: " << s.substr(0, n) << " " << n << endl;
    answer = s.substr(0, n); 
    return answer;
}