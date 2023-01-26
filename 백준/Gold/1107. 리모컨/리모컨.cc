#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

#define min(a,b) (a < b ? a : b)
using namespace std;

int min_cnt = 2147000000, num_int;
int btn_set[10];

void find(string num) {
    for(int i=0;i<10;i++) {
	    if(btn_set[i]) {
	        string tmp_num = num + to_string(i);
	        min_cnt = min( min_cnt, abs(num_int - stoi(tmp_num))+tmp_num.length());

    	    if(tmp_num.length() < 6) {
	    	    find(tmp_num);
	        }
	    }
    }
}

int main() {
    int n, k;
    // freopen("input.txt", "r", stdin);
    memset(btn_set, 1, sizeof(btn_set));

    cin >> num_int; 
    cin >> n;
    min_cnt = min(min_cnt, abs(100 - num_int));

    for(int i=0;i<n;i++) {
    	cin >> k;
	    btn_set[k] = 0;
    }
    
    // 다고장난 경우는 min_cnt가 답
    if(n<10) {
	    find("");
    }

    cout << min_cnt << endl;
    return 0;     
}
