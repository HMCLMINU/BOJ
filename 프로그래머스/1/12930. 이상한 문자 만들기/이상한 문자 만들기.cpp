#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    for (auto i : s) {
        if (cnt % 2 == 0) {
            answer += toupper(i);
        }
        else {
            answer += tolower(i);
        }
        if (i == ' ') {
            cnt = 0;
        }
        else {
            cnt++;
        }
        
    }
    return answer;
}