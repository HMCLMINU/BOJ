#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {    
    sort(arr.begin(), arr.end(), greater());
    int n=arr[0];
    int m=1, num=0;
    
    while(true){
        bool flag=false;
        num = n*m;
        for (int i=1; i<arr.size(); i++){
            if (num%arr[i]!=0){
                m++;
                flag=true;
                break;
            }
        }
        if (!flag) return num;
    }
    
}