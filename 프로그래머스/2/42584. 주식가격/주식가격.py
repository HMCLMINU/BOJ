def solution(prices):
    answer = [0 for _ in prices]
    stk = []
    for idx, v in enumerate(prices):
        if idx == 0:
            stk.append([idx, v])
        else:
            # 가격이 떨어진 경우
            while stk and stk[-1][1] > v:
                answer[stk[-1][0]] = idx - stk[-1][0]
                stk.pop()
            # if stk[-1][1] > v:
            #     answer[stk[-1][0]] = idx - stk[-1][0]
            #     stk.pop()
            
            stk.append([idx, v])
    
    for v in stk:
        if not answer[v[0]]:
            answer[v[0]] = len(prices) - 1 - v[0]
        
    return answer