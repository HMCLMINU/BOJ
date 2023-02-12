#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dr[4]={0, 1, 0, -1};
int dc[4]={1, 0, -1, 0};

struct Info{
    int row, col, dir, cost;
    Info (int a, int b, int c, int d){
        row=a;
        col=b;
        dir=c;
        cost=d;
    }
};

int changeDir(int a)
{
    if (a==0) return 2;
    if (a==1) return 3;
    if (a==2) return 0;
    if (a==3) return 1;
}

int solution(vector<vector<int>> board) {
    int answer = 2147000000;
    queue<Info> q;
    q.push(Info(0, 0, 0, 0));
    q.push(Info(0, 0, 1, 0));
    vector<vector<vector<int>>> visited(board.size(), 
                                vector<vector<int>> (board.size(), 
                                vector<int> (board.size(), 2147000000)));
    visited[0][0][0]=1;
    visited[0][0][1]=1;
    
    while (!q.empty()){
        Info v = q.front();
        q.pop();
        
        for (int i=0; i<4; i++){
            int nr = v.row+dr[i];
            int nc = v.col+dc[i];
            if (nr<0 || nr>(board.size()-1) || nc<0 || nc>(board.size()-1)) continue;
            if (board[nr][nc]==1) continue;
            int cost=0;
            if (v.cost){
                if (i!=v.dir){
                    cost=v.cost+600;
                }
                else {
                    cost=v.cost+100;
                }
            }
            else{
                // 출발
                cost = 100;
            }
            
            if (visited[nr][nc][i]>cost){
                visited[nr][nc][i]=cost;
                q.push(Info(nr, nc, i, cost));
            }
            
        }
    }
    for (int i=0; i<4; i++){ 
        if (answer > visited[board.size()-1][board.size()-1][i])
            answer = visited[board.size()-1][board.size()-1][i];
    }
    return answer;
}