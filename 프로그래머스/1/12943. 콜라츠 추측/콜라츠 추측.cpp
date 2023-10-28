#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n_copy = num;
    int cnt = 0;
    while (cnt <= 500) {
        if (n_copy == 1)
            return cnt;
        if (n_copy % 2 == 0)
            n_copy = n_copy/2;
        else {
            n_copy = n_copy * 3 + 1;
        }
        cnt++;
    }
    return -1; 
}