#include <iostream>
#include <vector>

using namespace std;

int N, M, ans; 
int map[502][502];
int ch[502][502];
int dr[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int dc[8] = {1, 0, -1, 0, 1, 1, -1, -1};
/*
테트로미노 하나로 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램
회전, 대칭 가능
현 위치에서 dfs로 연결 가능한 모든 도형 탐색, 정답 업데이트
*/

void DFS(int L, int sum, int row, int col)
{
    if (L==3){
        ans = max(ans, sum);
    }
    else {
        for (int i=0; i<7; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            
            if (!ch[nr][nc]){
                // 인접 존재 체크
                if (ch[nr][nc+1]==1 || ch[nr+1][nc]==1 ||
                ch[nr][nc-1]==1 || ch[nr-1][nc]==1){
                    ch[nr][nc]=1;
                    DFS(L+1, sum+map[nr][nc], nr, nc);
                    ch[nr][nc]=0;
                }
                
            }
        }
        
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin >> map[i][j]; 
        }
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            ch[i][j]=1;
            DFS(0, map[i][j], i, j);
            ch[i][j]=0;
        }
    }

    cout << ans << endl;
    return 0;
}