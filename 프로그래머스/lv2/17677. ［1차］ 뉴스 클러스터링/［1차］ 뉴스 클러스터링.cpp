#include <string>
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    string memo="";
    int count=0;
    
    map<string, int> memo1, memo2;
    set<string> s;
    
    for(int i=0;i<str1.length();i++){
        if(isalpha(str1[i])){
            str1[i]=toupper(str1[i]);
            memo+=str1[i];
        }
        else{
           memo="";
        }
        if(memo.length()==2){
            memo1[memo]++;
            s.insert(memo);
            memo=str1[i];
        }
    }
    
    memo="";
    
    for(int i=0;i<str2.length();i++){
        if(isalpha(str2[i])){
            str2[i]=toupper(str2[i]);
            memo+=str2[i];
        }
        else{
           memo="";
        }
        if(memo.length()==2){
            memo2[memo]++;
            s.insert(memo);
            memo=str2[i];
        }
    }
    
    int common_cnt = 0;
    int union_cnt = 0;
    for (auto i : s) {
        common_cnt += min(memo1[i], memo2[i]);
        union_cnt += max(memo1[i], memo2[i]);
    }
    
    if (union_cnt == 0) 
        answer = 65536;
    else
        answer = floor((double)common_cnt / (double)union_cnt * 65536);
    
    return answer;
}