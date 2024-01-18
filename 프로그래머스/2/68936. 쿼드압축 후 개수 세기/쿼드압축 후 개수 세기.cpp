#include <string>
#include <vector>

using namespace std;

vector<int> answer = {0, 0};

void compress(vector<vector<int>> &arr, int size, int row, int col)
{
    // 기저 조건
    if (size == 1) {
        if (arr[row][col] == 0)
            answer[0]++;
        else 
            answer[1]++;
        
        return;
    }
    // 현재 정사각형이 같은 숫자인지 확인
    int head = arr[row][col];
    bool can_compress = true;
    for (int i = row; i < row+size; i++) {
        for (int j = col; j < col+size; j++) {
            if (head != arr[i][j]) {
                can_compress = false;
                break;
            }
        }
    }
    // 압축 가능
    if (can_compress)
        answer[head]++;
    else {
        // n크기 정사각형을 n/2 4 조각 분할 & 시작 위치 전달
        compress(arr, size/2, row, col);
        compress(arr, size/2, row, col + size/2);
        compress(arr, size/2, row + size/2, col);
        compress(arr, size/2, row + size/2, col + size/2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    
    int n = arr.size();
    compress(arr, n, 0, 0);
    return answer;
}