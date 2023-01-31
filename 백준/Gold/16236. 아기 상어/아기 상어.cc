#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std; 

int N, time=0;
int map[21][21];
int visited[21][21];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

struct Shark{
    int cur_size=2, dist=0;
    int row=0, col=0, ate=0;
    Shark(int a, int b, int c){
        row=a;
        col=b;
        dist=c;
    }

    void update(){
        ate++;
        if (ate>=cur_size){
            cur_size++;
            ate=0;
        }
    }
};

struct Fish{
    int row, col, dist;
    Fish(int a, int b, int c){
        row=a;
        col=b;
        dist=c;
    }
    
    bool operator<(const Fish& a) const {
        if (dist == a.dist){
            if (row == a.row) return col > a.col;
            return row > a.row;
        }
        return dist > a.dist;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    queue<Shark> q;
    Shark baby_shark(0, 0, 0);
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> map[i][j];
            if (map[i][j]==9) {
                map[i][j]=0;
                visited[i][j]=1;
                q.push(Shark(i, j, 0));
            }
        }
    }
    // 먹을 수 있는 물고기가 없을 때까지
    while(true){
        // pq 초기화
        priority_queue<Fish> pq;
        // 먹을 수 있는 물고기 찾기
        while (!q.empty()){
            Shark s = q.front();
            q.pop();
            // 먹을 수 있는 물고기 추가
            if (map[s.row][s.col] && map[s.row][s.col] < s.cur_size){
                pq.push(Fish(s.row, s.col, s.dist));
            }

            for (int i=0; i<4; i++){
                int nr = s.row+dr[i];
                int nc = s.col+dc[i];
                if (nr<1 || nr>N || nc<1 || nc>N) continue;

                if (!visited[nr][nc] && map[nr][nc]<= s.cur_size){
                    visited[nr][nc]=1;
                    Shark ss(nr, nc, s.dist+1);
                    ss.cur_size = s.cur_size;
                    ss.ate = s.ate;
                    q.push(ss);
                }
            }
        }
        // 먹을 수 있는게 없음
        if (pq.empty()) break;
        // 물고기 먹기 & 시간, 상어 위치 업데이트 & 맵 업데이트
        Fish f = pq.top();
        baby_shark.update();
        baby_shark.row = f.row;
        baby_shark.col = f.col;
        ::time += f.dist;
        q.push(baby_shark);
        map[f.row][f.col]=0;
        // 방문처리 해제
        memset(visited, 0, sizeof(visited));
    }

    cout << ::time << endl;
    return 0;
}