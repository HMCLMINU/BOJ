#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string ss="";
    vector<string> v;
    char prev;
    for (int i=0; i<s.size(); i++){
        if (s[i]==' '){
            answer.push_back(' ');
        }
        else{
            if (prev==' '){
                if (islower(s[i])) s[i]=toupper(s[i]);
            }
            else{
                if (i==0){
                    if (islower(s[i])) s[i]=toupper(s[i]);
                }
                else{
                    if (isupper(s[i])) s[i]=tolower(s[i]);
                }
            }
            answer+=s[i];
        }
        
        prev = s[i];
    }
    return answer;
}