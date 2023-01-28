#include <iostream>

using namespace std;
/* M=3, N=4
<1,1> <2,2> <3,3> <1,4> 
<2,1> <3,2> <1,3> <2,4>
<3,1> <1,2> <2,3> <3,4>
*/
int T, M, N, x, y;
int m, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> T;
    for (int i=0; i<T; i++){
        cin >> M >> N >> x >> y;
        
        // res%M = x, res%N = y
        int res=x; // x 고정
        y %= N; // y가 N과 같을 때 0으로 만들기
        while ((res <= M*N) && res%N != y)
        {
            // 정답 후보는 M씩 증가하면서(x고정) y 확인
            res += M;
        }
        if (res > M*N) cout << -1 << endl;
        else cout << res << endl;
        
    }
    return 0;
}