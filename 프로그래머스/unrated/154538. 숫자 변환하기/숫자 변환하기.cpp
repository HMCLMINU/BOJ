#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    if (x==y) return 0;
    queue<pair<int, int>> q;
    q.push({y, 0});
    
    while (!q.empty()){
        pair<int, int> v=q.front();
        q.pop();
        
        if (v.first-n >= x) {
            if (v.first-n==x){
                answer=v.second+1;
                break;
            }
            q.push({v.first-n, v.second+1});
        }
        if (v.first%2==0 && v.first/2 >= x) {
            if (v.first/2==x){
                answer=v.second+1;
                break;
            }
            q.push({v.first/2, v.second+1});
        }
        if (v.first%3==0 && v.first/3 >= x) {
            if (v.first/3==x){
                answer=v.second+1;
                break;
            }
            q.push({v.first/3, v.second+1});
        }
    }
    if (answer==0) answer= -1;
    return answer;
}