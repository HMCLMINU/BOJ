#include <string>
#include <vector>

using namespace std;
int maxAlp, maxCop;
int dp[151][151];

int solve(int alp, int cop, const vector<vector<int>>& problems){
    // 모든 문제 해결 가능
    if (alp>=maxAlp && cop>=maxCop) return 0;
    
    // 메모리 최대 공간 제한
    if (alp > maxAlp) alp=maxAlp;
    if (cop > maxCop) cop=maxCop;
    // 구해야 하는 값  res
    // alp가 계속증가하고 cop가 고정 된 상태 종료 조건
    // 최소 값으로 이미 업데이트가 끝낫기 때문에 리턴
    int& res = dp[alp][cop];
    if (res!=0) return res;
    
    res = 1e9;
    // 문제 해결 (현재 상태에서 가능한 모든 경우 탐색)
    for (auto& i:problems){
        if (alp<i[0] || cop<i[1]) continue;
        res = min(res, solve(alp+i[2], cop+i[3], problems)+i[4]);
    }
    // 공부
    res = min(res, solve(alp+1, cop, problems)+1);
    res = min(res, solve(alp, cop+1, problems)+1);
    
    return res;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for (auto i:problems){
        maxAlp=max(maxAlp, i[0]);
        maxCop=max(maxCop, i[1]);
    }
    
    answer = solve(alp, cop, problems);
    
    return answer;
}