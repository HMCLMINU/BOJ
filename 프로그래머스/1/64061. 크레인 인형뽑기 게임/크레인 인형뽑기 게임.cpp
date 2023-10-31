#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stk;
    
    for (auto i : moves) {
        for (int row = 0; row < board.size(); row++) {
            /* 
                인형이 존재한다면 
                스택에 인형이 있다면 비교, 같은경우 +2 & 가장 위 인형 제거, 아니면 그냥 넣기
                없다면 그냥 넣기 
                빈칸 처리 & 다음 move
            */
            if (board[row][i-1]) {
                int n = board[row][i-1];
                if (!stk.empty()) {
                    if (n == stk.top()) {
                        answer += 2;
                        stk.pop();
                    }
                    else
                        stk.push(n);
                }
                else {
                    stk.push(n);
                }
                // 빈칸 처리 & 다음 move
                board[row][i-1] = 0;
                break;
            }
        }
    }
    return answer;
}