#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

struct Info {
    int storey;
    int cnt;
    Info (int a, int b) {
        storey = a;
        cnt = b;
    }
};

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int digit = storey % 10;
        storey = storey / 10; 
        // 5 인 경우 앞자리 숫자가 5 이상이면 올려주는 것이 유리
        if (digit == 5) {
            if (storey % 10 >= 5) {
                answer += (10 - digit);
                storey++;
            }
            else 
                answer += digit;
        }
        // 더하는게 이득
        else if (digit > 5) {
            answer += (10 - digit);
            storey++;
        }
        else {
            // 빼는게 이득
            answer += digit;
        }
    }
    return answer;
}