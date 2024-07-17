def solution(n):
    answer = ""
    for i in sorted(str(n), reverse=True):
        answer += i
        
    # return int(answer)
    # or
    return int("".join(sorted(str(n), reverse=True)))
        
    