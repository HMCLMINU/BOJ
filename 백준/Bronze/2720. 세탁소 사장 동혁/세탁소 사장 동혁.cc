#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin); 
    
    // Quarter = 0.25
    // Dime = 0.1 
    // Nickel = 0.05
    // Penny = 0.01
    int TC;
    cin >> TC;
    double cent, dollar;
    double quater = 25;
    double dime = 10;
    double nickel = 5;
    double penny = 1;
    
    for (int i = 0; i < TC; i++) {
        cin >> cent;
        dollar = cent;
        vector<int> v(4, 0);
        // quater
        v[0] = (int) dollar / quater;
        dollar = dollar - (v[0] * quater);
        // dime
        v[1] = (int) dollar / dime;
        dollar = dollar - (v[1] * dime);
        // nickel
        v[2] = (int) dollar / nickel;
        dollar = dollar - (v[2] * nickel);
        // penny
        v[3] = (int) dollar / penny;
        dollar = dollar - (v[3] * penny);
        
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    }
    
    return 0;
}