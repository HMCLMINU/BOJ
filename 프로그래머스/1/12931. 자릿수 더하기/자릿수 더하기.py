def solution(n):
    answer = 0
    for num in str(n):
        answer += int(num)
    
    # return sum(map(int, str(n)))
    return sum(int(i) for i in str(n))
    return answer