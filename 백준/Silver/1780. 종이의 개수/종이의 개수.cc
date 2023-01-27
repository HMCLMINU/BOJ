#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int N, a=0, b=0, c=0, k=0;
int ans[3]; 
int map[2200][2200];

bool check(int order, int rs, int cs)
{
    int num = map[rs][cs];
    for (int row=0; row<order; row++){
        for (int col=0; col<order; col++){
            if (map[rs+row][cs+col] != num) {
                return false; 
            }
        }
    }

    return true;
}

void DnC(int order, int rs, int cs)
{
    // 검사
    int num = map[rs][cs];
    // 맞다면 증가
    if (check(order, rs, cs)) ans[num+1]++;
    else {
        // 아니면 9등분 -> /3 , 최대 횟수 k번
        int div = order/3;
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                DnC(div, rs+i*div, cs+j*div);
            }
        }
    }
        
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> N;

    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            cin >> map[row][col];
        }
    }

    DnC(N, 0, 0);
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
    return 0;
}