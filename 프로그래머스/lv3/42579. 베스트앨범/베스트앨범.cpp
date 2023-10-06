#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Info{
    string genre;
    int total;
    int play;
    int id;
    Info (string a, int b, int c, int d){
        genre=a;
        total=b;
        play=c;
        id=d;
    }
    bool operator<(const Info& b) const {
        if (total == b.total) {
            if (play == b.play)
                return id > b.id;
            return play < b.play;
        }
        return total < b.total;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    // 총 재생 횟수 카운트
    unordered_map<string, int> hash;
    for (int i=0; i<genres.size(); i++) {
        hash[genres[i]]+=plays[i];
    }
    unordered_map<string, int> checker;
    // 우선순위 큐
    priority_queue<Info> pq;
    for (int i=0; i<genres.size(); i++) {
        pq.push(Info(genres[i], hash[genres[i]], plays[i], i));
    }

    while (!pq.empty()) {
        Info v=pq.top();
        pq.pop();
        if (checker[v.genre] < 2) {
            checker[v.genre]++;
            answer.push_back(v.id);
        }
    }
    return answer;
}