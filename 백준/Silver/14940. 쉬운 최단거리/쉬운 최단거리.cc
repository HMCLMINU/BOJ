#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int drow[4] = {0, 1, 0, -1};
int dcol[4] = {1, 0, -1, 0};

struct Info 
{
    int r;
    int c;
    int dist;
    Info(int a, int b, int dist) {
        r = a;
        c = b;
        this->dist = dist;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("test.txt", "r", stdin);
    int row, col; 
    int goal_row, goal_col;
    int num;
    cin >> row >> col;
    vector<vector<int>> map(1001, vector<int> (1001, 0));
    vector<vector<int>> visited(1001, vector<int> (1001, 0));
    vector<vector<int>> dist(1001, vector<int> (1001, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> num; 
            map[i][j] = num;
            if (num == 2) {
                goal_row = i;
                goal_col = j;
            }
        }
    }
    
    // 거리 계산 BFS
    queue<Info> q;
    q.push(Info(goal_row, goal_col, 0));
    visited[goal_row][goal_col] = 1;
    
    while (!q.empty()) {
        Info v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int n_row = v.r + drow[i];
            int n_col = v.c + dcol[i];
            int n_dist = v.dist + 1;
            // 범위 체크
            if (n_row < 0 || n_col < 0 || n_row >= row || n_col >= col)
                continue;
            // 방문안했으면서 갈 수 있는 곳
            if (visited[n_row][n_col] == 0 && map[n_row][n_col] != 0) {
                visited[n_row][n_col] = 1;
                dist[n_row][n_col] = n_dist;
                q.push(Info(n_row, n_col, n_dist));
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (visited[i][j] == 0 && map[i][j] == 1)
                cout << "-1" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}