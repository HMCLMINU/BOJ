#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str[3] = {"4", "1", "2"};

string solution(int n) {
    string answer = "";
    
    while (n > 0) {
        answer += str[ n % 3];
        if (n % 3 == 0) 
            n = (n / 3) - 1;
        else 
            n = n / 3;
    }
    reverse(answer.begin(), answer.end()); 
    return answer;
}