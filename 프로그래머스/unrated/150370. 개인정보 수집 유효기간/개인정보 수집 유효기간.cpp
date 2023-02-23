#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;
struct Info{
    int year, month, day;
};

Info convert(string& s){
    Info info;
    info.year = stoi(s.substr(0,4));
    info.month = stoi(s.substr(5,2));
    info.day = stoi(s.substr(8,2)); 
    return info;
}

bool check(Info& today, Info& pday, int due){
    int c_year=0, c_month=0, c_day=0;
    if (pday.month+due > 12) {
        c_year = pday.year+1;
        c_month = pday.month+due-12;
        if (pday.day-1 == 0){
            c_month-=1;
            c_day = 28;
        }
        else
            c_day = pday.day-1;
    }
    else {
        c_year=pday.year;
        c_month=pday.month+due;
        if (pday.day-1 == 0){
            c_month-=1;
            c_day = 28;
        }
        else
            c_day = pday.day-1;
    }
    // 파기
    int today_to_day = today.year*12*28 + today.month * 28 + today.day;
    int c_to_day = c_year*12*28 + c_month*28 + c_day;
    if (today_to_day > c_to_day)
        return true;
    else return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, string> m;
    
    Info n_today;
    n_today = convert(today);
    
    for (int i = 0; i < terms.size(); i++) {
        string num="", s="";
        s = terms[i].substr(0,1); 
        num = terms[i].substr(2);
        m.insert({s, num});
    }
    
    Info p_day;
    string p_kind="";
    int p_due=0;
    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i].substr(0, 10);
        p_day = convert(s);
        p_kind = privacies[i].substr(11, 1);
        p_due = stoi(m[p_kind]);
        
        if (check(n_today, p_day, p_due)) answer.push_back(i+1);
    }
    
    return answer;
}