#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define INF 100000000
// 플로이드 와샬

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
 
    vector<vector<int>> map(n+1, vector<int> (n+1, INF));
    for (int i=1; i<=n; i++) map[i][i]=0;
    
    for (int i=0; i<fares.size(); i++){
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (map[i][j] > map[i][k]+map[k][j]){
                    map[i][j] = map[i][k]+map[k][j];
                }
                    
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        if (map[s][i]==INF || map[i][a]==INF || map[i][b]==INF) continue;
        answer = min(answer, map[s][i]+map[i][a]+map[i][b]);
    }
    return answer;
}