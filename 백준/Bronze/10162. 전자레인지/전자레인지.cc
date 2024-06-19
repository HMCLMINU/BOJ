#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin); 
    
    int time;
    cin >> time;
    int a_bt = 300;
    int b_bt = 60;
    int c_bt = 10;
    vector<int> v(3, 0);

    v[0] = time / a_bt;
    time = time % a_bt; 
    v[1] = time / b_bt;
    time = time % b_bt;
    v[2] = time / c_bt;
    time = time % c_bt;
    if (time == 0)
        cout << v[0] << " " << v[1] << " " << v[2] << endl;
    else
        cout << -1 << endl;
    return 0;
}