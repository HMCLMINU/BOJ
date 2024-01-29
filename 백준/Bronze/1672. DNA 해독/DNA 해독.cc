#include <iostream>
#include <map>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    string s;
    map<pair<char, char>, char> m;
    m[make_pair('A', 'A')] = 'A';  
    m[make_pair('A', 'G')] = 'C'; 
    m[make_pair('A', 'C')] = 'A'; 
    m[make_pair('A', 'T')] = 'G'; 
    m[make_pair('G', 'A')] = 'C'; 
    m[make_pair('G', 'G')] = 'G'; 
    m[make_pair('G', 'C')] = 'T'; 
    m[make_pair('G', 'T')] = 'A'; 
    m[make_pair('C', 'A')] = 'A'; 
    m[make_pair('C', 'G')] = 'T'; 
    m[make_pair('C', 'C')] = 'C'; 
    m[make_pair('C', 'T')] = 'G'; 
    m[make_pair('T', 'A')] = 'G'; 
    m[make_pair('T', 'G')] = 'A'; 
    m[make_pair('T', 'C')] = 'G'; 
    m[make_pair('T', 'T')] = 'T'; 

    cin >> n;
    cin >> s;
    // if (n == 1) {
    //    cout << s << endl;
    //     return 0;
    // }
    while (true) {
        if (s.size() == 1)
            break;
        
        int k = s.size();
        char ss = m[make_pair(s[k-2], s[k-1])];
        s.pop_back();
        s.pop_back();
        s += ss;
    }
    cout << s << endl;
    return 0;
}