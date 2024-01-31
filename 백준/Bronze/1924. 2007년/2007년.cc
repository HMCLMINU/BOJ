#include <iostream>
#include <map>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int month, day;
    cin >> month >> day;
    map<int, int> m;
    map<int, string> d;
    m[1] = 31;
    m[3] = 31;
    m[5] = 31;
    m[7] = 31;
    m[8] = 31;
    m[10] = 31;
    m[12] = 31;
    m[4] = 30;
    m[6] = 30;
    m[9] = 30;
    m[11] = 30;
    m[2] = 28;
    d[0] = "SUN";
    d[1] = "MON";
    d[2] = "TUE";
    d[3] = "WED";
    d[4] = "THU";
    d[5] = "FRI";
    d[6] = "SAT";

    if (m[month] == 1) {
        cout << d[day % 7] << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i < month; i++) {
        cnt += m[i];
    }
    cnt += day;
    // cout << cnt << endl;
    cout << d[cnt%7] << endl;
    return 0;
}