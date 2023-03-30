#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 1;
    int enemySize = enemy.size(); 
    int left = 1;
    int right = enemy.size();
    
    while (left <= right) {
        int mid =  (left + right) / 2;
        int unkillable = k;
        int people = n;
        priority_queue<int> pq;
        for (int i=0; i<mid; i++) {
            pq.push(enemy[i]); 
        }
        
        while (!pq.empty()) {
            int v = pq.top();
            pq.pop();
            
            if (unkillable > 0) unkillable--;
            else {
                people -= v;
            } 
            
            if (people < 0) break;
        }
        
        if (people < 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            answer = left - 1;
        }
    }
    
    return answer;
}