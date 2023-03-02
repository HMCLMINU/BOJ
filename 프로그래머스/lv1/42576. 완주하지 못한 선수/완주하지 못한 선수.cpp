#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hash;    
    for (int i=0; i<participant.size(); i++) {
        hash[participant[i]]++;
    }
    
    for (int i=0; i<completion.size(); i++) {
        hash[completion[i]]--;
    }
    for (auto i:hash) {
        if (i.second==1) answer = i.first;
    }
    return answer;
}