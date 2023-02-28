#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_map<int, int> um;
    for (auto& i:skip) {
        um[i-'a']=1;
    }
    for (auto& i:s){
        int cnt=0;
        int n=i-'a';
        while (cnt<index){
            n++;
            if (n > 'z'-'a') n=0;
            if (!um[n]) cnt++;
        }
        char c=n+'a';
        answer+=c;
    }
    return answer;
}