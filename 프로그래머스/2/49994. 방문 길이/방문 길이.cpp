#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> visited(11, vector<int> (11, 0));

struct pose {
    int x;
    int y;  
};

struct Road {
    pose curr;
    pose next;
};

map<pair<pair<int, int>, pair<int, int>>, bool> um;
map<Road, int> road;

int solution(string dirs) {
    int answer = 0;
    pose p;
    p.x = 0;
    p.y = 0;
        
    for (auto i : dirs) {
        pose next_p;
        if (i == 'U') {
            next_p.x = p.x + dx[0];
            next_p.y = p.y + dy[0];
        }
        else if (i == 'R') {
            next_p.x = p.x + dx[1];
            next_p.y = p.y + dy[1];
        }
        else if (i == 'D') {
            next_p.x = p.x + dx[2];
            next_p.y = p.y + dy[2];
        }
        else if (i == 'L') {
            next_p.x = p.x + dx[3];
            next_p.y = p.y + dy[3];
        }
        
        // 범위 밖이면 p 유지
        if (next_p.x > 5 || next_p.x < -5 ||
           next_p.y > 5 || next_p.y < -5) {
            continue;
        }
        
        // mm[길] = 방문여부 로 길 등록
        if (!um[make_pair(make_pair(p.y, p.x), make_pair(next_p.y, next_p.x))]) {
            um[make_pair(make_pair(p.y, p.x), make_pair(next_p.y, next_p.x))] = true;
            um[make_pair(make_pair(next_p.y, next_p.x), make_pair(p.y, p.x))] = true;
            answer++;
        }

        // if (!road[r]) {
        //     road[r] = true;
        //     answer++;
        // }
        // 좌표 업데이트
        p.x = next_p.x;
        p.y = next_p.y;
        
    }
    return answer;
}