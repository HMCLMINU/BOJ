#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int map[101][101];
int visited[101][101];

struct Info {
    int row, col, dist;
    Info(int a, int b, int c) {
        row = a;
        col = b;
        dist = c;
    }
};

int solution(vector<string> board) {
    int answer = 0;
    queue<Info> q;
    int rowMax = board.size();
    int colMax = board[0].size();
    
    for (int i=0; i<rowMax; i++) {
        for (int j=0; j<colMax; j++) {
            if (board[i][j] == '.') map[i+1][j+1] = 0;
            else if (board[i][j] == 'D') map[i+1][j+1] = 1;
            else if (board[i][j] == 'R') {
                q.push(Info(i+1, j+1, 0));
                map[i+1][j+1] = 0;
                visited[i+1][j+1] = 1;
            }
            else map[i+1][j+1] = 2;
        }
    }
  
    while (!q.empty()) {
        Info v = q.front();
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nr = v.row+dr[i];
            int nc = v.col+dc[i];
            while (true) {
                if (map[nr][nc] == 1 || nr < 1 || nr > rowMax || nc < 1 || nc > colMax) break;
                nr += dr[i];
                nc += dc[i];
            }
            nr -= dr[i];
            nc -= dc[i];
            
            if (map[nr][nc] == 2) return v.dist+1;
            
            if (visited[nr][nc] != 1) {
                visited[nr][nc] = 1;
                q.push(Info(nr, nc, v.dist+1));
            }
        }
    }
    
    return -1;
}