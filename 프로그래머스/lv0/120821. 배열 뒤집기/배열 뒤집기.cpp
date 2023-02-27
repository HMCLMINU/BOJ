#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    vector<int>::reverse_iterator it;
    it = num_list.rbegin();
    for (it=num_list.rbegin(); it!=num_list.rend(); it++){
        answer.push_back(*it);
    }
    return answer;
}