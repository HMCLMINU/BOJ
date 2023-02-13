#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// d, l, r, u
int dr[4]={1, 0, 0, -1};
int dc[4]={0, -1, 1, 0};

struct Info{
    int row, col;
    string cmd;
    Info (int a, int b, string c){
        row=a;
        col=b;
        cmd=c;
    }
};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    bool ch[n+1][m+1][k+1];
    memset(ch, false, sizeof(ch));
    
    queue<Info> q;
    q.push(Info(x, y, ""));
    while (!q.empty()){
        Info v=q.front();
        q.pop();
        
        if (v.row==r && v.col==c){
            if (v.cmd.length()==k) return v.cmd;
        }
        if (v.cmd.length()==k) continue;
        for (int i=0; i<4; i++){
            int nr = v.row+dr[i];
            int nc = v.col+dc[i];
            if (nr<1 || nr>n || nc<1 || nc>m || ch[nr][nc][v.cmd.length()+1]) continue;
            string c="";
            if (i==0) c=v.cmd+"d";
            if (i==1) c=v.cmd+"l";
            if (i==2) c=v.cmd+"r";
            if (i==3) c=v.cmd+"u";
            ch[nr][nc][v.cmd.length()+1]=true;
            q.push(Info(nr, nc, c));
        }
    }
    
    return "impossible";
}