#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    stack<pair<int, int>> stk;
    for (int i=0; i<numbers.size(); i++){
        int n = numbers[i];
        while (!stk.empty() && stk.top().first < n){
            answer[stk.top().second]=n;
            stk.pop();
        }
        stk.push({n, i});        
    }
    
    return answer;
}