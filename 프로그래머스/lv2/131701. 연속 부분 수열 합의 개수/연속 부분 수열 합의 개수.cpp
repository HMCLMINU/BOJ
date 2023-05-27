#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> s;

int solution(vector<int> elements) {
    int answer = 0;
    int len = elements.size();
    // 원형수열 만들기
    for (int i=0; i<len; i++) { elements.push_back(elements[i]); }
    
    // left, right 포인터 사용하여 1~len 개수의 부분 수열 만들기
    for (int left=0; left<len; left++) {
        // 부분수열 원소 1개
        int sum = elements[left];
        s.insert(sum);
        // 부분수열 원소 2개 이상
        int cnt = 1; // 부분 수열의 원소 수 count
        int right = left+1;
        while (cnt < len) {
            sum += elements[right];
            s.insert(sum);
            cnt += 1;  
            right += 1;    
        }
    }
    
    answer = s.size();
    return answer;
}