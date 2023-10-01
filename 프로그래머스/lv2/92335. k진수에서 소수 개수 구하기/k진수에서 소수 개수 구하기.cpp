#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cmath>

using namespace std;
vector<int> v;
list<int> l;

void convert(int n, int k) {
    int rest = 0;
    while (1) {
        rest = n % k;
        n = n / k;
        
        l.push_front(rest);
        if (n == 0) break;
    }
    return; 
}

bool isprime(long long int n) {
    if (n == 1 || n == 0) return false;
   
    for (long long int i=2; i*i <= n; i++) {
        int rest = n % i;
        if (rest == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    convert(n, k);
    
    for (auto i=l.begin(); i != l.end(); i++) {
        if (*i != 0) {
            v.push_back(*i);
        }
        else {
            long long num = 0;
            for (int j=0; j<v.size(); j++) {
                num += v[j] * pow(10, v.size() - j-1);
            }
            if (isprime(num)) answer++;
            v.clear();
        }
    }
    if (!empty(v)) {
        long long num = 0;
        for (int j=0; j<v.size(); j++) {
            num += v[j] * pow(10, v.size() - j-1);
        }
        if (isprime(num)) answer++;
    }
    return answer;
}