#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int first=0, end=people.size()-1;
    
    while (first<=end) {
        if (people[first] + people[end] <= limit) {
            first++;
        }
        end--;
        answer++;
    }
    return answer;
}