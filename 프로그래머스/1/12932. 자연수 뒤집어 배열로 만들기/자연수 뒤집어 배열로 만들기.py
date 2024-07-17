def solution(n):
    answer = [int(i) for i in str(n)]
    answer.reverse()
    return list(map(int, reversed(str(n))))
    return answer