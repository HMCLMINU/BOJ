#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    unordered_map<char, int> um;
    
    for (auto& i:s){
        char c=i;
        if (isupper(i))
            c = tolower(i);
        if (c == 'p' || c=='y') um[c]++;
    }
    
    if (um['p'] != um['y']) return false;
    return answer;
}