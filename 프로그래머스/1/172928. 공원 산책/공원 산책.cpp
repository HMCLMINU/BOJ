#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;

struct Pose {
    int x;
    int y;
};
vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    Pose p;
    int max_x = park[0].size()-1;
    int max_y = park.size()-1;
    
    for (int i = 0; i<park.size(); i++) {
        if (park[i].find('S') != string::npos) {
            p.x = park[i].find('S');
            p.y = i;
            break;
        }
    }
    
    for (auto i : routes) {
        char dir = i[0];
        int dist = (int)i[2] - 48;
        int n_x, n_y;
        bool cant = false; 
        Pose p_copy = p;
        if (dir == 'E') {
            for (int d = 0; d<dist; d++) {
                n_x = p_copy.x + 1;
                n_y = p_copy.y;
                if (n_x < 0 || n_x > max_x || n_y < 0 || n_y > max_y || 
                   park[n_y][n_x] == 'X') {
                    cant = true;
                    break;
                }
                
                p_copy.x = n_x;
                p_copy.y = n_y;
            }
        }
        else if (dir == 'S') {
            for (int d = 0; d<dist; d++) {
                n_x = p_copy.x;
                n_y = p_copy.y + 1;
                
                if (n_x < 0 || n_x > max_x || n_y < 0 || n_y > max_y || 
                   park[n_y][n_x] == 'X') {
                    cant = true;
                    break;
                }
                p_copy.x = n_x;
                p_copy.y = n_y;
            }
        }
        else if (dir == 'W') {
           for (int d = 0; d<dist; d++) {
                n_x = p_copy.x - 1;
                n_y = p_copy.y;
                if (n_x < 0 || n_x > max_x || n_y < 0 || n_y > max_y || 
                   park[n_y][n_x] == 'X') {
                    cant = true;
                    break;
                }
                p_copy.x = n_x;
                p_copy.y = n_y;
            }
        }
        else {
            for (int d = 0; d<dist; d++) {
                n_x = p_copy.x;
                n_y = p_copy.y - 1;
                if (n_x < 0 || n_x > max_x || n_y < 0 || n_y > max_y || 
                   park[n_y][n_x] == 'X') {
                    cant = true;
                    break;
                }
                p_copy.x = n_x;
                p_copy.y = n_y;
            }
        }
        if (!cant) {
            p.x = p_copy.x;
            p.y = p_copy.y;
        }
        
    }
    answer.push_back(p.y);
    answer.push_back(p.x);
    return answer;
}