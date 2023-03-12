#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
    
int solution(int n, vector<int> cores) {
    ll answer = 0;
    int num_cores = cores.size();
    if (n <= num_cores) return n;
    // 시간이 주어질 때 몫 만큼 해결
    // 2개 코어, 10000시간, 50000개 작업
    // 25000 * 10000 시간
    ll left = 1;
    ll right = *max_element(cores.begin(), cores.end()) * n / cores.size();
    ll mid = 0;
    // sort(cores.begin(), cores.end());
    while (left <= right) {
        mid = (left + right) / 2;
        int workCnt = num_cores;
        int currWorkCnt = 0;
        int last = 0;
        
        for (int i=0; i<num_cores; i++) {
            workCnt += (mid / cores[i]);
            
            if (mid % cores[i] == 0) {
                workCnt--;
                currWorkCnt++;
            }
        }
        
        int totalWork = workCnt + currWorkCnt;
        
        if (workCnt >= n)
            right = mid - 1;
        else if (totalWork < n)
            left = mid + 1;
        else {
            for (int i=0; i<num_cores; i++) {
                if (mid % cores[i] == 0) {
                    workCnt++;
                }
                if (workCnt == n)
                    return i+1;
            }
        }
    }

    return answer;
}