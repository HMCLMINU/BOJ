#include <string>
#include <vector>

using namespace std;
// 가입자 > 판매액
int dr[4]={10, 20, 30, 40};
int ans1, ans2;

void dfs(vector<int>& discountRate, vector<vector<int>>& users, vector<int>& emoticons){
    if (discountRate.size()==emoticons.size()){
        int serviceUser=0;
        int salesMoney=0;
        for (int i=0; i<users.size(); i++){
            int userDiscountRate = users[i][0];
            int maxMoney = users[i][1];
            int tmpMoney=0;
            for (int j=0; j<emoticons.size(); j++){
                int dcr = discountRate[j];
                // 구매가능
                if (dcr >= userDiscountRate){
                    int newPrice = emoticons[j]*(100-dcr)/100;
                    tmpMoney+= newPrice;
                }
                // 한도 이상 쓴 경우
                if (tmpMoney>=maxMoney){
                    tmpMoney=0;
                    serviceUser++;
                    break;
                }
            }
            salesMoney+=tmpMoney;
        }
        if (serviceUser>ans1){
            ans1=serviceUser;
            ans2=salesMoney;
        }
        else if (serviceUser==ans1){
            if (salesMoney > ans2){
                ans2 = salesMoney;
            }
        }
    }
    else{
        for (int i=0; i<4; i++){
            discountRate.push_back(dr[i]);
            dfs(discountRate, users, emoticons);
            discountRate.pop_back();
        }
    }
};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> dcRate;
    dfs(dcRate, users, emoticons);
    answer.push_back(ans1);
    answer.push_back(ans2);
    return answer;
}