#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    float num = (float)num1 / (float)num2 * 1000;
    answer = floor(num);
    return answer;
}