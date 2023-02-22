#include <string>
#include <vector>

using namespace std;

bool check(int a)
{
    for (int i=2; i*i<=a; i++){
        if (a%i==0) return false;
    }
    return true;
}

int solution(int n) {
    int answer = 0;
    
    for (int i=2; i<=n; i++){
        if (check(i)) answer++;
    }
    return answer;
}