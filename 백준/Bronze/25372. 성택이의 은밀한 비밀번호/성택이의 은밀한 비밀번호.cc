#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    for (auto i = 0; i < n; i++) {
        cin >> str;
        if (str.size() >=6 && str.size() <= 9)
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    } 

    return 0;
}