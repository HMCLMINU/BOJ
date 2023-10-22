#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
// 1- 0,0 2- 0,1 3- 0,2
// 4- 1,0 5 - 1,1 6- 1,2 
// 위치: (현재수-1)/3, (현재수-1)%3
// 0인 경우 3,1
// 키패드 거리가 같다면 오른잡이는 오른손, 왼손잡이는 왼손
string solution(vector<int> numbers, string hand) {
    string answer = "";

    // 왼손, 오른손 현재 위치 기록
    int curr_l = 10, curr_r = 12;
    int nx, ny;
    for (int i=0; i<numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            curr_l = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            curr_r = num;
        }
        else {
            if (num == 0) {
                ny = 3;
                nx = 1;
            }
            else {
                ny = (num-1)/3;
                nx = (num-1)%3; 
            }
            // 2,1 - 1,1
            // 2,1 - 0,2 
            int dist_l, dist_r;
            if (curr_l == 0) 
                dist_l = abs(ny-3) + abs(nx - 1);
            else 
                dist_l = abs(ny-(curr_l-1)/3) + abs(nx - (curr_l-1)%3);
            
            if (curr_r == 0)
                dist_r = abs(ny-3) + abs(nx - 1);
            else
                dist_r = abs(ny-(curr_r-1)/3) + abs(nx - (curr_r-1)%3);
            
            if (dist_l == dist_r) {
                if (hand == "left") {
                    answer += "L";
                    curr_l = num; 
                }
                else {
                    answer += "R";
                    curr_r = num;
                }
            }
            else if (dist_l < dist_r) {
                answer += "L";
                curr_l = num;
            }
            else {
                answer += "R";
                curr_r = num;
            }
        }
    }
    return answer;
}