#include <vector>
#include <iostream>

using namespace std;

int answer;

void dfs(int L, int idx, int sum, vector<int> nums) 
{
    if (L == 3) {
        for (int i=2; i*i<=sum; i++) {
            if (sum % i == 0)
                return;
        }
        answer++;
        return;
    }        
    else {
        for (int i=idx; i<nums.size(); i++) {
            dfs(L+1, i+1, sum+nums[i], nums);
        }
    }
}

int solution(vector<int> nums) {
    
    dfs(0, 0, 0, nums);
    
    return answer;
}