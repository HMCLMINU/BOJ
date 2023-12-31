#include <string>
#include <vector>

using namespace std;
//14 
// t*x + y <= max
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    // 시전 시간, 1초당 회복량, 추가회복량
    // 공격 시간, 피해량
    int time = 1;
    int curr_health = health;
    int s_success = 0;
    int curr_attack_idx = 0;
    int max_attack_idx = attacks.size()-1;
    
    while (1) {
        if (curr_attack_idx > max_attack_idx)
            break;
        // 현재 시간에 공격이 있는지 판단
        // 공격이 있다면
        // 공격이 없다면 연속 성공
        if (time == attacks[curr_attack_idx][0]) {
            s_success = 0;
            curr_health -= attacks[curr_attack_idx][1];
            curr_attack_idx++;
        }
        else {
            curr_health += bandage[1];
            s_success++;
        }
        // 추가 회복 성공
        if (s_success == bandage[0]) {
            s_success = 0;
            curr_health += bandage[2];
        }
        
        if (curr_health > health)
            curr_health = health;
        
        if (curr_health <= 0)
            return -1;
        
        time++;
    }
    
    answer = curr_health;
    if (curr_health <= 0)
        answer = -1;
    
    return answer;
}