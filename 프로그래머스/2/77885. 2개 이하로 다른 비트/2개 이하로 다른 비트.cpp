#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto i : numbers) {
        // 짝수인경우 +1 이 정답
        if (i % 2 == 0)
            answer.push_back(i+1);
        else {
            /*
                홀수인 경우 가장 뒤쪽 0을 1로 바꾼 후 그 다음 비트를 0으로 바꿈
                reverse -> 0111 -> rfind('0') -> 1011 
            */
            string s;
            while (true) {
                if (i == 0)
                    break;
                s += to_string(i%2);
                i = i/2;
            }
            reverse(s.begin(), s.end());
            string new_s = "0" + s;
            long long idx = new_s.rfind('0');
            new_s[idx] = '1';
            new_s[idx+1] = '0';
            long long num = 0;
            for (int j = new_s.size()-1; j>=0; j--) {
                num += (new_s[j] - 48) * pow(2, new_s.size()-(j+1));
            }
            answer.push_back(num);
            // cout << new_s << " " << num << endl;
        }          
    }
    return answer;
}