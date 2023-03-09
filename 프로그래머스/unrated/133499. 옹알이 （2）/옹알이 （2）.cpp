#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for(int i;i<babbling.size();i++)
    {
        string temp1="";
        string temp2="";
        for(char c:babbling[i])
        {
            temp1+=c;
            if(temp1 == "aya"||temp1 == "ye"||temp1 == "woo"||temp1 == "ma")
            {
                if(temp2 == temp1) break;
                temp2=temp1;
                temp1="";
            }
        }
        if(temp1.size()==0) answer++;
    }
    return answer;
}