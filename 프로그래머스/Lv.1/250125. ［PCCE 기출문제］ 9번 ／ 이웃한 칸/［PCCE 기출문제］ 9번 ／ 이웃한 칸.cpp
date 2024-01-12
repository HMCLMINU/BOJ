#include <string>
#include <vector>

using namespace std;

vector<int> dr = {0, 1, 0, -1}; 
vector<int> dc = {1, 0, -1, 0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    int count = 0;
    string curr_color = board[h][w];
    
    for (int i = 0; i < dr.size(); i++) {
        int nr = h + dr[i];
        int nc = w + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n)
            continue;
        if (curr_color == board[nr][nc])
            count++;
    }
    answer = count;
    return answer;
}