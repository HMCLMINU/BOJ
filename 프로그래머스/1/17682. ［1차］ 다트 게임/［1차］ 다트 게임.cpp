#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
vector<int> score;
int solution(string dartResult) {
    int answer = 0;
    /*
        숫자 또는 대문자
        점수 기록
    */
    for (int i=0; i < dartResult.size(); ) {
        if (isdigit(dartResult[i])) {
            int num = 0;
            // 10 처리
            if (isdigit(dartResult[i+1])) {
                num = 10;
                i++;
            }
            else
                num = (int)dartResult[i]-48;
            
            if (dartResult[i+1] == 'S') 
                score.push_back(num);
            else if (dartResult[i+1] == 'D')
                score.push_back(pow(num, 2));
            else 
                score.push_back(pow(num, 3));
            i+=2;
        }
        else {
            int cnt = score.size();
            if (dartResult[i] == '*') {
                if (cnt == 1) {
                    score[cnt-1] = score[cnt-1]*2;
                }
                else {
                    score[cnt-1] = score[cnt-1]*2;
                    score[cnt-2] = score[cnt-2]*2;
                }
            }
            if (dartResult[i] == '#') {
                score[cnt-1] = score[cnt-1] * -1;
            }
            i++;
        }
        
    }
    for (auto i : score) {
        answer += i;
        // cout << i << endl;
    }
            
    return answer;
}