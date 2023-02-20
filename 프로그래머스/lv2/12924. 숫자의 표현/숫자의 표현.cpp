#include <string>
#include <vector>
#include <iostream>

using namespace std;

int target;

void dfs(int num, int sum, int& answer){
    if (sum >= target) {
        if (sum==target) answer++;
    }
    else{
        sum+=num;
        dfs(num+1, sum, answer);
    }
}

int solution(int n) {
    int answer = 0;
    target=n;
    for (int i=1; i<=n; i++){
        dfs(i, 0, answer);
    }
    return answer;
}