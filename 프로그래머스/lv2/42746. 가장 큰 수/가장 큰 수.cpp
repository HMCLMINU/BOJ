#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// descending order
bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> arr;
    //1
    for (auto i : numbers) {
       arr.push_back(to_string(i)); 
    }
    sort(arr.begin(), arr.end(), cmp);
    if (arr[0] == "0")
        return "0";
    
    for (int i =0; i < arr.size(); i++) {
        answer += arr[i];
    }
    
    return answer;
}