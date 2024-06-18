#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int N;
    cin >> N;
    vector<int> buildings;
    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;
        buildings.push_back(height);
    }

    vector<int> cnt(N, 0); // 각 빌딩에서 보이는 빌딩 갯수 카운트
    for (int i = 0; i < N-1; i++) {
        double max_rate = -9999999999;
        for (int j = i+1; j < N; j++) {
            double curr_rate = (double)(buildings[j] - buildings[i])/(j - i);
            if (curr_rate > max_rate) { // 보인다면
                cnt[i]++;
                cnt[j]++;
                max_rate = curr_rate;
            }
        }
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;
    return 0;
}