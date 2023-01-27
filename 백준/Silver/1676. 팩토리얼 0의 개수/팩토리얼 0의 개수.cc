#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    int a=0, b=0;
    for (int i=2; i<=N; i++){
        int x = i;

        while (x%2==0){
            x/=2;
            a++;
        }
        while (x%5==0){
            x/=5;
            b++;
        }
    }

    cout << b << endl;

    return 0; 
    
}