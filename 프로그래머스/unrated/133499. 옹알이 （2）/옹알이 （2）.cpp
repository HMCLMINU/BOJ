#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> v({"aya", "ye", "woo", "ma"});
unordered_map<string, int> hash;

void registString(string str, string prev) 
{
    if (str.size() > 0 && str.size() <= 30) {
        ::hash[str] = 1;
       
        if (prev != "aya")
            registString(str+"aya", "aya");
        if (prev != "ye")
            registString(str+"ye", "ye");
        if (prev != "woo")
            registString(str+"woo", "woo");
        if (prev != "ma")
            registString(str+"ma", "ma");
    }
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    registString("aya", "aya");
    registString("ye", "ye");
    registString("woo", "woo");
    registString("ma", "ma");
    
    for (auto i : babbling) {
        if (::hash[i]) answer++;
    }
    return answer;
}