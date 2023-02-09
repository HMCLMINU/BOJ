#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    ios::sync_with_stdio(false);
    vector<int> answer;
    vector<int> sheet(e+1, 0);
    for (int i = 1; i <= e; i++) {
        sheet[i]++;
    }
    //2부터 e까지의 숫자에 대한 약수 정보 삽입
    for (int i = 2; i <= e; i++) {
        for (int k = 1; k <= e / i; k++) {
            sheet[i * k]++;
        }
    }
    
    // for (int i=1; i<=e; i++){
    //     int cnt=0;
    //     if (sheet[i]!=0){
    //         if (i*2<=e) {
    //             sheet[i*2]=sheet[i]+1;
    //         }
    //         continue;
    //     }
    //     for (int j=1; j*j<=i; j++){
    //         if (i%j==0){
    //             if (i/j!=j) cnt+=2;
    //             else cnt+=1;
    //         }
    //     }
    //     sheet[i]=cnt;
    // }
    
    vector<int> s(e+1, 0);
    int max=0, idx=0;
    for (int i=e; i>0; i--){
        if (sheet[i]>=max){
            max = sheet[i];
            idx=i;
        }
        s[i]=idx;
    }
    
    for (int i=0; i<starts.size(); i++){
        answer.push_back(s[starts[i]]);
    }

    return answer;
}