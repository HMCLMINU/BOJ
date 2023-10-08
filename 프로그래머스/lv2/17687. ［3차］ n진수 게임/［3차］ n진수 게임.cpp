#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[] = {"0", "1", "2", "3", "4", "5", "6",
               "7", "8", "9", "A", "B", "C", "D","E","F"};

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int min_cnt = m * t;
    string num_str = "0";
    int num = 1;
    while (true) {
        int num_copy = num;
        string str_tmp;
        while (num_copy > 0) {
            str_tmp += str[num_copy % n];
            num_copy = num_copy / n;
        }
        reverse(str_tmp.begin(), str_tmp.end());
        num_str += str_tmp;
        num++;
        if (num_str.size() >= min_cnt) break;
    }
    
    int cnt = 0;
    for (int i = p-1; i < num_str.size(); i+=m) {
        answer += num_str[i];
        cnt++;
        if (t == cnt) break;
    }
    return answer;
}