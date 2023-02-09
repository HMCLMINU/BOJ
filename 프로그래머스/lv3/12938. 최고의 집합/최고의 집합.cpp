#include <string>
#include <vector>
#include <iostream>

using namespace std;

int l, N;
int calc=0;


vector<int> solution(int n, int s) {
    vector<int> answer;
    if (s%n==0){
        int k = s/n;
        for (int i=0; i<n; i++) answer.push_back(k);
    }
    else{
        int a=s/n;
        int r=s%n;
        if (a==0) return {-1};
        for (int i=0; i<n-r; i++) answer.push_back(a);
        for (int i=0; i<r; i++) answer.push_back(a+1);
    }
    
    return answer;
}