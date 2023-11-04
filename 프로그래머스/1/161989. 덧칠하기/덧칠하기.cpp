#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    unordered_map<int, int> um;
    vector<int> wall(n);
    
    for (auto i : section) {
        /* 
            색칠한게 아닌 경우 색칠
        */
        if (!um[i]) {
            for (int j = 0; j<m; j++) {
                um[i+j] = 1;
            }
            answer++;
        }
    }
    
    return answer;
}