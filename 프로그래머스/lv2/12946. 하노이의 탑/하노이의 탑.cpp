#include <string>
#include <vector>

using namespace std;

void hanoi(vector<vector<int>>& answer, int n, int st, int dst) {
    if (n==1){
        answer.push_back({st, dst});
        return;
    }   
    else{
        hanoi(answer, n-1, st, 6-st-dst);
        answer.push_back({st, dst});
        hanoi(answer, n-1, 6-st-dst, dst);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(answer, n, 1, 3);
    return answer;
}