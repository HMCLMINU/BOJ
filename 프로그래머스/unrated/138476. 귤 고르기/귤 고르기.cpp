#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;
 
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for (int i=0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto& i:m){
        pq.push({i.second, i.first});
    }
    
    while (k>0){
        k-=pq.top().first;
        answer++;
        pq.pop();
    }
    return answer;
}