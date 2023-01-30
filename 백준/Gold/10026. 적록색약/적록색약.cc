#include <iostream>
#include <string>
#include <queue>

using namespace std; 

int N;
string str;
char map[101][101];
char map_fixed[101][101];
int ch[101][101];
int ch2[101][101];
int dr[4] = {1, 0 , -1, 0}; 
int dc[4] = {0, 1, 0, -1};

struct Data{
    int row, col;
    char color;
    Data (int a, int b, char c){
        row=a;
        col=b;
        color=c;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> str;
        for (int j=0; j<str.size(); j++){
            map[i+1][j+1]=str[j];
            map_fixed[i+1][j+1]=str[j];
            if (str[j]=='R'){
                map_fixed[i+1][j+1]='G'; 
            }
        }
    }
    int ans1=0, ans2=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            queue<Data> q;
            queue<Data> q2;
            if (!ch[i][j]) {
                q.push(Data(i, j, map[i][j]));
                ch[i][j]=1;
                ans1++;
            }
            if (!ch2[i][j]) {
                q2.push(Data(i, j, map_fixed[i][j]));
                ch2[i][j]=1;
                ans2++;
            }

            while (!q.empty()){
                Data s = q.front();
                q.pop();
                
                for (int k=0; k<4; k++){
                    int nr = s.row + dr[k];
                    int nc = s.col + dc[k];
                    
                    if ( nr<1 || nr>N || nc<1 || nc>N) continue;
                    if (!ch[nr][nc] && s.color==map[nr][nc]){
                        ch[nr][nc]=1;
                        q.push(Data(nr, nc, map[nr][nc]));
                    }
                }
            }

            while (!q2.empty()){
                Data s = q2.front();
                q2.pop();
                
                for (int k=0; k<4; k++){
                    int nr = s.row + dr[k];
                    int nc = s.col + dc[k];
                    
                    if ( nr<1 || nr>N || nc<1 || nc>N) continue;
                    if (!ch2[nr][nc] && s.color==map_fixed[nr][nc]){
                        ch2[nr][nc]=1;
                        q2.push(Data(nr, nc, map_fixed[nr][nc]));
                    }
                }
            }

        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}