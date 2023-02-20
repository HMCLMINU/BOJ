#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, int> m;
    int cnt=1;
    int loop=1;
    string prev="";
    for (int i=0; i<words.size(); i++){
        m[words[i]]++;
        if (m[words[i]]>1) {
            answer.push_back(cnt);
            answer.push_back(loop);
            return answer;
        }
        if (!prev.empty()){
            if (prev[prev.size()-1]!=words[i][0]){
                answer.push_back(cnt);
                answer.push_back(loop);
                return answer;
            }
        }
        prev=words[i];
        cnt++;
        if (cnt>n) { 
            cnt=1;
            loop++;
        }
    }
    return {0, 0};
}