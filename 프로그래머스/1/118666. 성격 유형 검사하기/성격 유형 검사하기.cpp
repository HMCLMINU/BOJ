#include <string>
#include <vector>
#include <map>

using namespace std;

// 성격 유형 survey "비동의동의"
// 선택 chocies

vector<int> score = {3, 2, 1, 0, 1, 2, 3};
vector<string> personality = {"RT", "CF", "JM", "AN"};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    
    for (int i=0; i<survey.size(); i++) {
        if (choices[i] < 4) {
            m[survey[i][0]] += score[choices[i]-1];
        }
        else {
            m[survey[i][1]] += score[choices[i]-1];
        }
    }    
    
    for (auto i : personality) {
        if (m[i[0]] == m[i[1]])
            answer+=i[0];
        else {
            if (m[i[0]] > m[i[1]])
                answer += i[0];
            else
                answer += i[1];
        }
    }
    
    return answer;
}