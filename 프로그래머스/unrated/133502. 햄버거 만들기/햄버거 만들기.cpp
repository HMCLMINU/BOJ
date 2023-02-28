#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 1231
int order[4]={1, 2, 3, 1};
int solution(vector<int> ingredient) {
    int answer = 0;
    string str="";
    for (auto& i:ingredient){
        str+=to_string(i);
    }
    int pos=0;
    while (str.find("1231", pos)!=string::npos){
        int idx = str.find("1231", pos);
        str.erase(idx, 4);
        if (idx>2) pos=idx-3;
        answer++;
    }
    return answer;
}