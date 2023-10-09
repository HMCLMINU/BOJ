#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> dict;
string s[] = {"A", "B", "C", "D", "E", "F", "G", 
             "H", "I", "J", "K", "L", "M", "N",
             "O", "P", "Q", "R", "S", "T", "U", 
             "V", "W", "X", "Y", "Z"};

vector<int> solution(string msg) {
    vector<int> answer;
    int num_cnt = 26;
    for (int i = 0; i < num_cnt; i++) {
        dict[s[i]] = i+1;
    }
    string str_w;

    for (int i = 0; i < msg.size(); ) {
        // w 찾기
        int j = i;
        while (true) {
            str_w += msg[j];
            if (dict[str_w] == 0) {
                // 사전에 없는 경우
                dict[str_w] = ++num_cnt; // w+c 등록
                str_w = str_w.substr(0, j-i);
                answer.push_back(dict[str_w]); // 출력
                i += str_w.size();
                str_w = ""; // 초기화
                break;
            }
            j++;
        }
    }
    return answer;
}