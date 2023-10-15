#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// skill이 주어졌을때 skill_trees에서 가능한 tree의 개수
// skill[0] ~ skill[n] 찾기
// skill 첫번째 원소 못찾았는데 다음 원소를 찾을 경우 불가능
// skill 첫번째 원소 못찾았는데 다음 원소 또한 계속 없을 경우 가능
// skill 첫번째 원소 찾았고 나머지도 찾거나 못찾는다면 가능
// unorderd_map 에 위치 등록
// 출력하면서 인덱스 비교

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i=0; i<skill_trees.size(); i++) {
        unordered_map<char, int> um;
        int prev_idx = -1;
        int curr_idx = 0;
        int is_possible = 1;
        for (auto s:skill) {
            if (skill_trees[i].find(s) != string::npos) {
                um[s] = skill_trees[i].find(s);
            }
            else um[s] = 100;
        }

        for (auto s:skill) {
            curr_idx = um[s];
            if (curr_idx < prev_idx) {
                is_possible = 0;
                break;
            }
            prev_idx = curr_idx;
        }
        if (is_possible) answer++;
    }
    return answer;
}