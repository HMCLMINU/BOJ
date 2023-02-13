#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i=begin; i<=end; i++){
        if (i==1) {
            answer.push_back(0);
            continue;
        }
        
        bool flag=false;
        int max=0;
        for (long long j=2; j*j<=i; j++) {
            if (i%j==0) { 
                if (i/j>10000000){
                    if (j>max){
                        max=j;
                    }
                }
                else {
                    if (i/j > max){
                        max=i/j;
                        break;
                    }
                }
            } 
        }
        if (max==0) answer.push_back(1);
        else answer.push_back(max);
    }
    return answer;
}