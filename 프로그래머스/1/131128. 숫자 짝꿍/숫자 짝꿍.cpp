#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    unordered_map<char, int> x_um;
    unordered_map<char, int> y_um;
    // 공통 문자 찾기 & 갯수 기록
    for (auto i:X) x_um[i]++;
    for (auto i:Y) y_um[i]++;
    
    for (auto i:x_um) {
        // X에서 나타난 것이 Y에도 있다면 더 적은 숫자만큼 기록
        if (y_um[i.first]) {
            if (i.second < y_um[i.first]) {
                for (int cnt = 0; cnt < i.second; cnt++)
                    answer+= i.first;
            }
            else {
                for (int cnt = 0; cnt < y_um[i.first]; cnt++) 
                    answer+= i.first;
            }
        }
    }
    if (answer == "")
        return "-1";
    
    sort(answer.begin(), answer.end(), greater<>());
    if (answer[0] == '0')
        return "0";
    return answer;
}