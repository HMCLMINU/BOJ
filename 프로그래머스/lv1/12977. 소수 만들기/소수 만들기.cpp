#include <vector>
#include <iostream>

using namespace std;

int sum;
int answer;

void dfs(int L, int idx, vector<int> nums) 
{
    if (L == 3) {
        cout << sum << endl;
        for (int i=2; i*i<=sum; i++) {
            if (sum % i == 0)
                return;
        }
        answer++;
        return;
    }        
    else {
        cout << "L: " << L << "idx: " << idx << endl;
        for (int i=idx; i<=nums.size()-3; i++) {
            sum += nums[i];
            dfs(L+1, idx+1, nums);
            sum -= nums[i];
        }
    }
}

int solution(vector<int> nums) {
    
    dfs(0, 0, nums);
    
    return answer;
}