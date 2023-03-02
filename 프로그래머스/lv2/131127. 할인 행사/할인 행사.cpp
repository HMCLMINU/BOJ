#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // want - number 해싱
    unordered_map<string, int> hash;
    for (int i=0; i<want.size(); i++){
        hash[want[i]] = number[i];
    }
    // discount 항목 현재 부터 10일 간의 항목 카운트 
    unordered_map<string, int> discountHash;
    for (int i=0; i<9; i++){
        discountHash[discount[i]]++;
    }
    
    for (int i=9; i<discount.size(); i++){
        discountHash[discount[i]]++;
        // 검사
        bool ch=false;
        for (auto& i:hash){
            if (discountHash[i.first] != i.second) {
                ch=true;
                break;
            }
        }
        
        if (!ch) answer++;
        // 처음 항목 제거
        if (discountHash[discount[i-9]]>0) discountHash[discount[i-9]]--;
    }
    return answer;
}