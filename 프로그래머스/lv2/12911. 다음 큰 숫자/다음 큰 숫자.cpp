#include <string>
#include <vector>

using namespace std;

int binaryCount(int n){
    int cnt=0;
    while (n>0){
        if (n%2 == 1) cnt++;
        n/=2;
    }    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    answer = n+1;
    int num = binaryCount(n);
    while (true) {
        int cmp = binaryCount(answer);
        if (cmp==num) return answer;
        answer++;
    }
}