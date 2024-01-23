#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int tc, num;
    double score; 
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> num;
        double avg = 0;
        vector<double> v;
        for (int j = 0; j < num; j++) {
            cin >> score;
            avg += score;
            v.push_back(score);
        }
        avg = (double) avg / num;
        int cnt = 0;
        for (auto n : v) {
            if (n > avg) {
                cnt++;
            }
        }

        double rate = (double) cnt / num;
        cout << fixed;
        cout.precision(3);
        cout << rate * 100 * 1000 / 1000 << "%" << endl;
        // cout << avg << endl;
    }
    return 0;
}