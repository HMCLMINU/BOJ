#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int maxKeySize;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> hash;
    
    for (auto& i:keymap) {
        for (int j=0; j<i.size(); j++){
            if (hash[i[j]]!=0 && hash[i[j]]>j+1)
                hash[i[j]]=j+1;
            else if (!hash[i[j]]) hash[i[j]]=j+1;
        }
    }
    
    for (auto& i:targets){
        int sum=0;
        bool ch=false;
        for (int j=0; j<i.size(); j++){
            if (!hash[i[j]]) {
                sum=-1;
                break;
            }
            else sum+=hash[i[j]];
        }
        answer.push_back(sum);
    }
    
    return answer;
}