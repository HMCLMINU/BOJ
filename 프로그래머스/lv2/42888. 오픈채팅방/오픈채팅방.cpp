#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;
// 큐로 가지고 있고, 아이디별 최종 이름은 해시에 저장
vector<string> solution(vector<string> record) {
    vector<string> answer;
    // id 별 최종 이름 저장 해시
    // key: id, value : name
    unordered_map<string, string> id_hash;
    // id, 명령 저장 큐
    queue<pair<string, string>> q;
    for (int i=0; i<record.size(); i++) {
        string str="", cmd="", id="", name="";
        stringstream ss;
        ss.str(record[i]);
        int cnt=0;
        while (ss >> str) {
            if (cnt==0) cmd = str;
            if (cnt==1) id = str;
            if (cnt==2) name = str;
            cnt++;
        }
        // Leave 일때는 name이 공백이므로 바꾸면 안됨
        if (cmd == "Change" || cmd == "Enter") {
            id_hash[id] = name;
        }
        q.push({id, cmd});
    }
    
    while (!q.empty()) {
        pair<string, string> v = q.front();
        q.pop();
        string s="";
        s+=id_hash[v.first];
        if (v.second == "Enter") {
            s+="님이 들어왔습니다.";
            answer.push_back(s);
        }
        else if (v.second == "Leave") {
            s+="님이 나갔습니다.";
            answer.push_back(s);
        }
        s="";
    }
    return answer;
}