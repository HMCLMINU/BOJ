#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

bool cmp(int& a, int& b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N >> K;
    vector<int> coin(N, 0);
    for (int i=0; i<N; i++){
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end(), cmp);
    int ans=0;
    while (K > 0){
        int c=0;
        for (int i=0; i<coin.size(); i++){
            if (coin[i] <= K) {
                c = coin[i];
                break;
            }
        }
        while (K >= c){
            K -= c;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}