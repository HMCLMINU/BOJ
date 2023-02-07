#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<book_time.size(); i++){
        string st = book_time[i][0];
        string et = book_time[i][1];
        int nst = stoi(st.substr(0,2))*60+stoi(st.substr(3));
        int net = stoi(et.substr(0,2))*60+stoi(et.substr(3));
        
        while (!pq.empty() && pq.top()+10 <= nst){
            pq.pop();
        }
        pq.push(net);
        answer = max(answer, (int) pq.size());
    }
    
    return answer;
}