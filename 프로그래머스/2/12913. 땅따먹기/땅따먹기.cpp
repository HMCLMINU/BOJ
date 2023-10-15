#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// land : N행 4열, 같은 열을 연속해서 밟을 수 없다
// dp : 3+8 과 5+7 비교
 

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int end = land.size();
    for (int i=0; i<land.size()-1; i++) {
        land[i+1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i+1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i+1][2] += max(land[i][0], max(land[i][1], land[i][3]));
        land[i+1][3] += max(land[i][0], max(land[i][1], land[i][2]));
    }
    answer = *max_element(land[end-1].begin(), land[end-1].end());
    return answer;
}