#include <iostream>
#include <queue>

using namespace std; 

int N, x;

struct Data{
    int x;
    Data(int a){
        x=a;
    }
    bool operator<(const Data& a) const {
        if (abs(x) == abs(a.x)) return x > a.x;
        return abs(x) > abs(a.x);
    }
};

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);

    cin >> N; 
    priority_queue<Data> pq;
    for (int i=0; i<N; i++){
        cin >> x;
        if (x == 0){
            if (!pq.empty()){
                Data a = pq.top();
                pq.pop();
                cout << a.x << "\n";
            }
            else {
                cout << 0 << "\n";
            } 
        }
        else{
            pq.push(Data(x));
        }
    }
    return 0;
}