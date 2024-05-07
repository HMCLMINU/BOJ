#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
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
//     int n=*max_element(tangerine.begin(), tangerine.end());
//     vector<int> v(n+1, 0);
//     for (int i=0; i<tangerine.size(); i++){
//         v[tangerine[i]]++;
//     }
    
//     sort(v.begin(), v.end(), greater());
//     for (int i=0; i<v.size(); i++){
//         k-=v[i];
//         answer++;
//         if (k<=0) break;
//     }
    return answer;
}