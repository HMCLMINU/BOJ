#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a%b==0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b)
{
    int k=1;
    while (true)
    {
        int tmp=b*k;
        if (!tmp%a) return tmp;
        k++; 
    }
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    if (n>m){
        int tmp=m;
        m=n;
        n=tmp;
    }
    int a = gcd(m, n);
    answer.push_back(a);
    answer.push_back(m*n/a);
    
    return answer;
}