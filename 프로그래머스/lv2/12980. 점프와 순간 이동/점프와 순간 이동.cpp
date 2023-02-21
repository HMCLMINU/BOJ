#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int ans=0;
    while(true) {
        if (n%2==1){
            n-=1;
            ans++;
            if (n==0) return ans;
        }
        else{
            n/=2;
        }
    }
    
}