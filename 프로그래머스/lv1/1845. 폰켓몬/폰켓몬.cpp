#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> hash;
    int spieces=0;
    for (int i=0; i<nums.size(); i++) {
        if (!hash[nums[i]]) spieces++;
        hash[nums[i]]=1;
    }
    
    int choiceNum = nums.size()/2;
    if (spieces >= choiceNum) answer = choiceNum;
    else answer = spieces;
    return answer;
}