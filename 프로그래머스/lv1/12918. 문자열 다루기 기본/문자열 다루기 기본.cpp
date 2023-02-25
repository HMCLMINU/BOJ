#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size()==4 || s.size()==6) {
        for (int i=0; i<s.size(); i++){
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
    else
        return false;

}