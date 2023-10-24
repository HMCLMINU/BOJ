#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int c = x;
    int num = 0;
    while (c > 0) {
        num += c % 10;
        c = c / 10;
    }
    if (x % num == 0)
        return true;
    else 
        return false;
}