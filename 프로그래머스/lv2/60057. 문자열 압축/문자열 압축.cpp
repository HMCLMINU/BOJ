#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 2147000;
    // 검사 길이
    string str;
    for (int i=1; i<=s.size(); i++){
        string a="";
        string tmp=s.substr(0, i);
        int cnt=1;
        
        for (int j=i; j<s.size(); j+=i){
            if (tmp == s.substr(j, i))
                cnt++;
            else{
                if (cnt != 1)
                    a += to_string(cnt);
                a+=tmp;
                tmp=s.substr(j, i);
                cnt=1;
            }
        }
        if (cnt>1) a+= to_string(cnt);
        a+=tmp;
        if (answer > a.size())
            answer = a.size();
    }
    return answer;
}