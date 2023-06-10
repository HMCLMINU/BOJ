#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Info 
{
    int length = 0;
    vector<int> index;
    
    Info(int a, int b, int c) {
        length = a;
        index.push_back(b);
        index.push_back(c);
    }
    
    bool operator<(Info a) const {
        if (length == a.length)
            return index[0] > a.index[0];
        return length > a.length;
    }
};

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int left = 0 , right = 0;
    int partial_sum = sequence[left];
    priority_queue<Info> pq;

    while (left<=right && right < sequence.size())
    {
        if (partial_sum < k) partial_sum += sequence[++right];
        else if (partial_sum == k) {
            pq.push(Info(right-left, left ,right));
            partial_sum -= sequence[left++];
        }
        else {
            partial_sum -= sequence[left++];
        }
    }
        
    return pq.top().index;
}