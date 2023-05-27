#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int t_value = 0;
    int b_value = 0;
    
    for (long long i = left; i< right + 1; i++) {
        t_value = i / n;
        b_value = i % n;
        
        if (t_value >= b_value + 1) {
            b_value += t_value - b_value;
        }
        
        answer.push_back(b_value + 1);
    }
    return answer;
}