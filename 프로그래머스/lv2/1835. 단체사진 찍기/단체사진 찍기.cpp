#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<string> element={"A", "C", "F", "J", "M", "N", "R", "T"};
vector<string> cpy_data;
int visited[8];
int cnt;

int check(int idx1, int idx2, string op, string num){
    int n = stoi(num);
    if (op=="="){
        if (abs(idx1-idx2)-1 == n) return 1;
        return 0;
    }
    if (op=="<"){
        if (abs(idx1-idx2)-1<n) return 1;
        return 0;
    }
    if (op==">"){
        if (abs(idx1-idx2)-1>n) return 1;
        return 0;
    }
}

void dfs(vector<string>& ch){
    if (ch.size()==8){
        bool flag=true;
        for (int i=0; i<cpy_data.size(); i++){
            string a1 = cpy_data[i].substr(0, 1);
            string a2 = cpy_data[i].substr(2, 1);
            string op = cpy_data[i].substr(3, 1);
            string num = cpy_data[i].substr(4);
            int idx1=0, idx2=0;
            for (int j=0; j<ch.size(); j++){
                if (a1 == ch[j]) { idx1=j; }
                if (a2 == ch[j]) { idx2=j; }
            }
            if (!check(idx1, idx2, op, num)) {
                flag=false;
                break;
            }
        }
        if (flag) cnt++;
    }
    for (int i=0; i<8; i++){
        if (!visited[i]){
            visited[i]=1;
            ch.push_back(element[i]);
            dfs(ch);
            ch.pop_back();
            visited[i]=0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer=0;
    cpy_data=data;
    vector<string> c;
    memset(visited, 0, sizeof(visited));
    cnt=0;
    dfs(c);
    answer=cnt;
    return answer;
}