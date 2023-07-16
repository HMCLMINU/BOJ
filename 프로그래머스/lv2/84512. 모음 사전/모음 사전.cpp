#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

vector<char> v{'A', 'E', 'I', 'O', 'U'};

int solution(string word) {
    int answer = 0;
    int n = v.size();
    int count = 0;
    unordered_map<string, int> um;
    string ss;
    
    for (int i=0; i<n; i++) {
        ss += v[i];
        count++;
        um[ss] = count;
        
        for (int ii=0; ii<n; ii++) {
            ss += v[ii];
            count++;
            um[ss] = count;
            
            for (int iii=0; iii<n; iii++) {
                ss += v[iii];
                count++;
                um[ss] = count;
                for (int iiii=0; iiii<n; iiii++) {
                    ss += v[iiii];
                    count++;
                    um[ss] = count;
                    for (int iiiii=0; iiiii<n; iiiii++) {
                        ss += v[iiiii];
                        count++;
                        um[ss] = count;
                        ss.pop_back();
                    }
                    ss.pop_back();
                }
                ss.pop_back();
            }
            ss.pop_back();
        }
        ss.pop_back();   
    }
    
    answer = um[word];
    return answer;
}