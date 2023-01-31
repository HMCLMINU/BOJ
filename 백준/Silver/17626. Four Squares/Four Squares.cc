#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[1]=1;

    for (int i=2; i<=n; i++){
        int minn = 2147000000;
        for (int j=1; j*j <= i; j++){
            int tmp = i-j*j;
            minn = min(minn, dp[tmp]);
        }
        dp[i] = minn+1;
    }
    cout << dp[n];

    return 0;
}