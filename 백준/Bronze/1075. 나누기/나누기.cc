#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    
    int N, F;
	int answer = 0;
	cin >> N >> F;
	// 뒤 두 자리를 먼저 00으로 바꾸기
	N /= 100;
	N *= 100;
	
	while((N+answer) % F != 0 && answer < 100) answer ++;
	
	if (answer < 10) cout << "0" + to_string(answer) << endl;
	else cout << answer << endl;

    return 0;
}