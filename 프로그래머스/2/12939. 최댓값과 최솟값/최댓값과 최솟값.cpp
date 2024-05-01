#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    string str="";
    // 숫자 분리
    for (int i=0; i<s.size(); i++){
        if (s[i]!=' '){
            str+=s[i];
        }
        else{
            v.push_back(stoi(str));
            str="";
        }
    }
    // 마지막 str 분리
    v.push_back(stoi(str));
    // *min/max_element로 최소/최대값 리턴 후 string 변환
    answer+= to_string(*min_element(v.begin(), v.end()));
    answer+= " ";
    answer+= to_string(*max_element(v.begin(), v.end()));
    return answer;
}