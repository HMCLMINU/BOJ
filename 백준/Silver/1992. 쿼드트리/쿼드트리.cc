#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int N, map[64][64];
string str; 
vector<string> v;

bool check(int L, int row, int col)
{
    int n = map[row][col];
    // check
    for (int i=0; i<L; i++){
        for (int j=0; j<L; j++){
            if (n != map[row+i][col+j])
                return false;         
        }
    }
    return true;
}

void DnC(int L, int row, int col)
{
    if (check(L, row, col)){
        int num = map[row][col];
        // cout << row << " " << col << " " << L << endl;
        v.push_back(to_string(num));
    }
    else{
        int div = L/2;
        v.push_back("(");
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                DnC(div, row+i*div, col+j*div);
            }
        }
        v.push_back(")"); 
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> str;
        for (int j=0; j<N; j++){
            map[i][j] = str[j]-'0';
        }
    }
    if (N==1){
        cout <<"("<<map[0][0]<<")"<<endl;
        return 0;
    }

    DnC(N, 0, 0); 
    for (auto& i:v){
        cout << i; 
    }
    cout << endl;

    return 0;
}