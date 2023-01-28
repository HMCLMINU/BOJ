#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, res;
string str;
// N은 o의 개수, M은 str길이, I뒤에 OI가 N개 붙어있는게 몇개
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // freopen("input.txt", "r", stdin);
    cin >> N;
    cin >> M;
    cin >> str;

    vector<string> v(N+1);
    v[1]="IOI";
    for (int i=2; i<=N; i++){
        v[i]=v[i-1]+"OI";
    }

    while(true){
        if (str.find(v[N]) != string::npos){
            res++; 
        }
        else break;
        str = str.substr(str.find(v[N])+1);
    }
    
    cout << res << endl;
    return 0;
}