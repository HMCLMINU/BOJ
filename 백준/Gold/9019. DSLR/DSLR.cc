#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int T, B, A;
bool visited[10000];

struct Resister{
    int d1, d2, d3, d4;
    int num;
    string cmd="";
    Resister(int a){
        save(a);
    }
    void save(int a){
        num = a;
        d4=a%10;
        a/=10;
        d3=a%10;
        a/=10;
        d2=a%10;
        a/=10;
        d1=a%10;
    }

    void D(){
        if (num*2 > 9999) { num = (num*2)%10000; } 
        else { num*=2; }
        save(num);
    }

    void S(){
        if (num==0) { num=9999; }
        else { num-=1; }
        save(num);
    }

    void L(){
        int n=d1;
        d1=d2;
        d2=d3;
        d3=d4;
        d4=n;
        num = d1*1000+d2*100+d3*10+d4;
    }
    void R(){
        int n=d4;
        d4=d3;
        d3=d2;
        d2=d1;
        d1=n;
        num = d1*1000+d2*100+d3*10+d4;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> A >> B;

        queue<Resister> q;
        q.push(Resister(A));
        memset(visited, 0, sizeof(visited));
        visited[A] = 1;

        while (!q.empty()){
            Resister v = q.front();
            q.pop();

            if (v.num == B){
                cout << v.cmd << "\n";
                break;
            }
            
            // D
            Resister r(v.num);
            r.D();
            if (!visited[r.num]){
                visited[r.num]=1;
                r.cmd = v.cmd+'D';
                q.push(r);
            }
            // S
            r.save(v.num);
            r.S();
            if (!visited[r.num]){
                visited[r.num]=1;
                r.cmd = v.cmd+'S';
                q.push(r);
            }
            // L
            r.save(v.num);
            r.L();
            if (!visited[r.num]){
                visited[r.num]=1;
                r.cmd = v.cmd+'L';
                q.push(r);
            }
            // R
            r.save(v.num);
            r.R();
            if (!visited[r.num]){
                visited[r.num]=1;
                r.cmd = v.cmd+'R';
                q.push(r);
            }
        }
    }
    return 0;
}