#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int map[101][101][101];

int dr[6]={1, 0, -1, 0, 0, 0};
int dc[6]={0, 1, 0, -1, 0, 0};
int dh[6]={0, 0, 0, 0, 1, -1};

struct Info{
    int r, c, h, dist;
    Info(int a, int b, int height, int d){
        r=a;
        c=b;
        h=height;
        dist=d;
    }
};

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> M >> N >> H;
    queue<Info> q;
    int cnt=0, m_cnt=0;
    for (int h=1; h<=H; h++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=M; j++){
                cin >> map[i][j][h];
                if (map[i][j][h]==1) {
                    q.push(Info(i,j,h,0));
                    cnt++;
                }
                if (map[i][j][h]==-1) m_cnt++;
            }   
        }
    }

    if (cnt == M*N*H-m_cnt){
        cout << 0 << endl;
        return 0;
    }

    int ans=0;
    while (!q.empty()){
        Info v = q.front();
        q.pop();

        for (int i=0; i<6; i++){
            int nr = v.r + dr[i];
            int nc = v.c + dc[i];
            int nh = v.h + dh[i];
            if (nr<1 || nr>N || nc<1 || nc>M || nh<1 || nh>H) continue;

            if (map[nr][nc][nh]==0){
                map[nr][nc][nh]=1;
                ans = max(ans, v.dist+1);
                cnt++;
                q.push(Info(nr, nc, nh, v.dist+1));
            }
        }
    }

    if (cnt != M*N*H-m_cnt) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}