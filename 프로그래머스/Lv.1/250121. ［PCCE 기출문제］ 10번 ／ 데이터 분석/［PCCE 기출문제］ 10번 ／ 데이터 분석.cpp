#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info 
{
    int code;
    int date;
    int maximum;
    int remain;
    vector<int> data;
    string sort_by;
    
    info(vector<int> v, string s) {
        code = v[0];
        date = v[1];
        maximum = v[2];
        remain = v[3];
        sort_by = s;
        data = {code, date, maximum, remain};
    }
    
    bool operator<(const info v) const {
        if (sort_by == "code")
            return code > v.code;
        else if (sort_by == "date")
            return date > v.date;
        else if (sort_by == "maximum")   
            return maximum > v.maximum;
        else
            return remain > v.remain;
    }
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    priority_queue<info> ext_data;
    for (auto v : data) {
        if (ext == "code") {
            if (v[0] < val_ext)
                ext_data.push(info(v, sort_by));
        }
        if (ext == "date") {
            if (v[1] < val_ext)
                ext_data.push(info(v, sort_by));
        }
        if (ext == "maximum") {
            if (v[2] < val_ext)
                ext_data.push(info(v, sort_by));
        }
        if (ext == "remain") {
            if (v[3] < val_ext)
                ext_data.push(info(v, sort_by));
        }
    }
    
    while (!ext_data.empty()) {
        answer.push_back(ext_data.top().data);
        ext_data.pop();
    }
    return answer;
}