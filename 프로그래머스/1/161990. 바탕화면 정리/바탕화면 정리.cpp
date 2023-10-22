#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

#define MAX 123456789
using namespace std;
// 빈칸 ".", 파일 "#"
// 최소한의 이동거리를 갖는 한번의 드래그로 모든 파일 선택해서 한번에 지우기
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    // wallpaper에서 행, 열 최소 최대 찾기
    // 끝점은 행,열 +1
    int min_row = MAX, min_col = MAX, max_row =0, max_col=0;
    for (int i=0; i<wallpaper.size(); i++) {
        int row, col;
        for (int j=0; j<wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                row = i;
                col = j;
                min_row = min(min_row, row);
                min_col = min(min_col, col);
                max_row = max(max_row, row);
                max_col = max(max_col, col);
            }
        }
        
    }
    
    max_row++;
    max_col++;
    answer.push_back(min_row);
    answer.push_back(min_col);
    answer.push_back(max_row);
    answer.push_back(max_col);
    return answer;
}