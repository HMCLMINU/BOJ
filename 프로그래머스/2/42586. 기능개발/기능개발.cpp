#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> release;
    int n = progresses.size();
    for (int i = 0; i < progresses.size(); i++) {

        if (((100 - progresses[i]) % speeds[i]) == 0) {
            release.push((100 - progresses[i]) / speeds[i]);
        }
        else {
            release.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }
    while (!release.empty()) {
        int d = release.front(), p = 1;
        release.pop();

        while ((!release.empty()) && (release.front() <= d)) {
            release.pop();
            p++;
        }
        answer.push_back(p);
    }
    return answer;
}