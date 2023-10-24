#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int x, y;
    if (a > b) {
        x = b;
        y = a;
    }
    else {
        x = a;
        y = b;
    }
    
    long long k = y-x+1; 
    if (k%2 == 1) {
        answer = k/2 * (y + x) + (y+x)/2;
    }
    else {
        answer = k/2 * (y + x);
    }
    return answer;
}