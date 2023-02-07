#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int map[101][101];
int dr[4]={0, 1, 0, -1};
int dc[4]={1, 0, -1, 0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int h = maps.size();
    int w = maps[0].size();
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (isdigit(maps[i][j])){
                map[i+1][j+1]=maps[i][j]-'0';
            }
        }
    }
    
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            int sum=0;
            if (map[i][j]>0){
                // dfs
                stack<pair<int, int>> stk;
                stk.push({i, j});
                sum=map[i][j];
                map[i][j]=0;
                while (!stk.empty()){
                    pair<int, int> v=stk.top();
                    stk.pop();
                    
                    for (int i=0; i<4; i++){
                        int nr = v.first + dr[i];
                        int nc = v.second + dc[i];
                        
                        if (nr < 1 || nr > h || nc < 1 || nc > w) continue;
                        
                        if (map[nr][nc]>0){
                            sum+=map[nr][nc];
                            map[nr][nc]=0;
                            stk.push({nr, nc});
                        }
                    }
                }
            }
            if (sum>0) answer.push_back(sum);
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.empty()) answer.push_back(-1);
    return answer;
}