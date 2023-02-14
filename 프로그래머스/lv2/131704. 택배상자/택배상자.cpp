#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> stk;
    int idx=0;
    int p=1;
    while (!stk.empty() || idx<order.size()){
        int now = order[idx];
        for (; p<=now; p++)
            stk.push(p);
        
        if (stk.top() == now){
            answer++;
            stk.pop();
            idx++;
        }
        else break;
    }
    
    return answer;
}