#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
// 바로 앞 선수를 추월할 때 추월한 선수의 이름을 부른다

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> um;
    for (int i = 0; i< players.size(); i++) {
        um[players[i]] = i;
    }
    
    for (auto i : callings) {
        int curr_idx = um[i];
        int next_idx = curr_idx - 1;
        string front_player = players[next_idx];
        // swap
        players[next_idx] = i;
        players[curr_idx] = front_player;
        
        // update hash
        um[i] = next_idx;
        um[front_player] = curr_idx;
    }
    
    return answer = players;
}