#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int N, M, lx, ly, rx, ry;
    int ans = 0; 
    cin >> N >> M;
    vector<vector<int>> p(102, vector<int>(102, 0));
    for (int i = 0; i < N; i++) {
        cin >> lx >> ly >> rx >> ry;
        
        for (int row = lx; row <= rx; row++) {
            for (int col = ly; col <= ry; col++) {
                p[row][col]++;
                
            }
        }
    }
    
    for (int i = 0; i < 102; i++) {
        for (int j = 0; j < 102; j++) {
            if (p[i][j] > M) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}