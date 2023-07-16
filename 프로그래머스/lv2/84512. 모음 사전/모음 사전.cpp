#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<char> v{'A', 'E', 'I', 'O', 'U'};
int cnt = -1;
string target="";
int answer = 0;

void dfs(string w)
{
    cnt++;
    
    if (w == target) {
        answer = cnt;
        return;
    }
    
    if (w.size() >= 5) return;
    
    for (int i=0; i<5; i++) {
        dfs(w + v[i]);
    }    
}

int solution(string word) {
    target = word;     
    dfs("");

    return answer;
}