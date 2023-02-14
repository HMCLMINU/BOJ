#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dr[4]={0, 1, 0, -1};
int dc[4]={1, 0, -1, 0};
vector<int> answer;

struct Info{
    int row, col, dist;
    Info (int a, int b, int c){
        row=a;
        col=b;
        dist=c;
    }
};

bool bfs(vector<vector<string>>& m, queue<Info> q)
{
    vector<vector<bool>> ch(5, vector<bool> (5, false));
    
    while (!q.empty()){
        Info v=q.front();
        q.pop();
        
        if (ch[v.row][v.col] || v.dist==2) continue;
        
        ch[v.row][v.col]=true;
        for (int i=0; i<4; i++){
            int nr = v.row+dr[i];
            int nc = v.col+dc[i];
            if (nr<0 || nr>4 || nc<0 || nc>4 || m[nr][nc]=="X") continue;
            int ndist = v.dist+1;
            if (!ch[nr][nc]){
                if (m[nr][nc]=="P") {
                    return false;
                }
                
                q.push(Info(nr, nc, ndist));
            }
            
            
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    
    for (int i=0; i<places.size(); i++){
        vector<vector<string>> map(5, vector<string> (5, ""));
        vector<pair<int, int>> v;
        for (int j=0; j<places[i].size(); j++){
            for (int k=0; k<places[i][j].size(); k++){
                map[j][k] = places[i][j][k];
                if (map[j][k]=="P") v.push_back({j, k}); 

            }
        }
        bool flag=false;
        for (auto i:v){
            queue<Info> q;
            q.push(Info(i.first, i.second, 0));
            if (!bfs(map, q)){
                flag=true;
                break;
            }
        }
        if (flag) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}