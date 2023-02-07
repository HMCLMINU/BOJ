#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Time{
    int sh, sm;
    int eh, em;
    Time(vector<string>& a){
        sh = (a[0][0]-'0')*10+(a[0][1]-'0');
        sm = (a[0][3]-'0')*10+(a[0][4]-'0');
        eh = (a[1][0]-'0')*10+(a[1][1]-'0');
        em = (a[1][3]-'0')*10+(a[1][4]-'0');
    }
    bool check(Time& b){
        if (em+10 >= 60){
            return (eh+1)*100+(em+10-60) <= (b.sh*100+b.sm);
        }
        return (eh*100+em+10) <= (b.sh*100+b.sm);
    }
    
    bool operator<(const Time& a) const {
        return eh*100+em > a.eh*100+a.em;
    }
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    sort(book_time.begin(), book_time.end());
    vector<Time> v;
    for (int i=0; i<book_time.size(); i++){
        v.push_back(Time(book_time[i]));
    }
    priority_queue<Time> pq;
    pq.push(v[0]);
    answer++;
    for (int i=1; i<v.size(); i++){
        while (!pq.empty()){
            Time t = pq.top();
            if (t.check(v[i])){
                pq.pop();
            }
            else {
                break;
            }
        }
        pq.push(v[i]);
        cout << pq.size() << endl;
        if (answer < pq.size())
            answer = pq.size();
    }
    
    return answer;
}