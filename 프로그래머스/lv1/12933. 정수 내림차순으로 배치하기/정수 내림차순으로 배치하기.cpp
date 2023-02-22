#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool cmp(char& a, char& b){
    return a > b;
}
long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end(), cmp);
    // answer=stoi(s);
    for (int i=0; i<s.size(); i++){
        answer+= (s[i]-'0')*pow(10, s.size()-i-1);
    }
    return answer;
}