#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    if (lost.size() == 0)
        return answer;
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    // 가져왔지만 도난당한 애 처리
    for (int i = 0; i<lost.size(); i++) {
        for (int j=0; j<reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                answer++;
                lost[i] = -1;
                reserve[j] = -100;
                break;
            }            
        }
    }
    // 이미 처리한 애가 아니라면 작은 애한테 먼저 빌리기
    // 작은 애가 없다면 큰 애한테 빌리기
    for (int i = 0; i < lost.size(); i++) {
        int curr_lost = lost[i];
        for (int j = 0; j < reserve.size(); j++) {
            int curr_reserve = reserve[j];
            if (curr_lost != -1 && curr_lost - curr_reserve == 1) {
                answer++;
                reserve[j] = -100;
                break;
            }
            if (curr_lost != -1 && curr_lost - curr_reserve == -1) {
                answer++;
                reserve[j] = -100;
                break;
            }
        }
    }
    return answer;
}