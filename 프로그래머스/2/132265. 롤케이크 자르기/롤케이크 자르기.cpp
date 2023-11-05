#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
 
    unordered_map<int, int> um1;
    unordered_map<int, int> um2;
    // 전체 토핑 기록
    for (auto i : topping) {
        um2[i]++;
    }
    // um1과 um2의 크기가 같다면 토핑 가짓수가 같음
    // 단, 토핑의 개수가 0이 될 경우 삭제해줌
    for (int i=0; i<topping.size()-1; i++) {
        um1[topping[i]]++;
        um2[topping[i]]--;
        
        if (um2[topping[i]] == 0)
            um2.erase(topping[i]);
        
        if (um1.size() == um2.size()) answer++;
    }
    return answer;
}