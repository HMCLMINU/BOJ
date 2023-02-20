#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    string str="";

    for (int i=0; i<s.size(); i++){
        if (s[i]!=' '){
            str+=s[i];
        }
        else{
            v.push_back(stoi(str));
            str="";
        }
    }
    v.push_back(stoi(str));
    answer+= to_string(*min_element(v.begin(), v.end()));
    answer+= " ";
    answer+= to_string(*max_element(v.begin(), v.end()));
    return answer;
}