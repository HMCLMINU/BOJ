#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    // 등대 체크 해쉬
    unordered_map<int, int> hash;
    unordered_map<int, int> removedRoad;
    int num = lighthouse.size();
    while (true){
        int sum=0;
        for (auto i:removedRoad){
            sum+=i.second;
        }
        if (sum==num) break;
        // 그래프 만들기
        vector<vector<int>> graph(n+1);
        for (int i=0; i<num; i++){
            if (!removedRoad[i]){
                graph[lighthouse[i][0]].push_back(lighthouse[i][1]);
                graph[lighthouse[i][1]].push_back(lighthouse[i][0]);
            }
        }

        for (int i=1; i<=n; i++) {
            // 리프 등대면 연결 등대 on
            if (graph[i].size()==1 && !hash[graph[i][0]] && !hash[i]) {
                // cout << graph[i][0] << endl;
                hash[graph[i][0]]=1;
                answer++;
            }
        }
        
        // 켜진 등대랑 연결된 뱃길 제거
        for (int i=0; i<lighthouse.size(); i++){
            if (hash[lighthouse[i][0]] || hash[lighthouse[i][1]]){
                removedRoad[i]=1;
            } 
        }
    }
   
    return answer;
}