using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    for (int i=1; i<=count; i++) {
        sum += i * price;
    }
    if (sum - money > 0) return sum - (long long) money;
    else return 0;
}