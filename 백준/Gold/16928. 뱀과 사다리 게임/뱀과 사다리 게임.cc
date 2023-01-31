#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M, a, b; 
/*
사다리만 타면서 도착
*/
int dp[101]; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> M;
    
    unordered_map<int, int> ladder;
    unordered_map<int, int> snake;
    vector<int> ch(101, 2147000000);
    for (int i=0; i<N; i++){
        cin >> a >> b;
        ladder[a]=b;
    }

    for (int i=0; i<M; i++){
        cin >> a >> b;
        snake[a]=b;
    }  

    queue<int> q;
    q.push(1);
    ch[1]=0;

    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (int i=1; i<=6; i++){
            int nv = v+i;
            
            if (nv > 100) continue;
            
            if (ladder.find(nv)!=ladder.end()){
                if (ch[ladder[nv]] > ch[v]+1) {
                    ch[ladder[nv]]=ch[v]+1;
                    q.push(ladder[nv]);
                } 
            }
            if (snake.find(nv)!=snake.end()){
                if (ch[snake[nv]]>ch[v]+1) {
                    ch[snake[nv]]=ch[v]+1;
                    q.push(snake[nv]);
                }
            }
            
            if (ladder.find(nv)==ladder.end() && snake.find(nv)==snake.end()){
                if (ch[nv] > ch[v]+1){
                    ch[nv]=ch[v]+1;
                    q.push(nv);
                }
            }
            
        }
    }

    cout << ch[100] << endl;
    return 0;
}