#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int curr_et = routes[0][1];
    answer++;
    for (int i=1; i<routes.size(); i++){
        int n_curr_st = routes[i][0];
        int n_curr_et = routes[i][1];
        if (curr_et < n_curr_st){
            curr_et = n_curr_et;
            answer++;
        }
    }
  
    return answer;
}