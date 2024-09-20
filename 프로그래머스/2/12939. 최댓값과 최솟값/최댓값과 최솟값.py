def solution(s):
    answer = ''
    n = s.split(' ')
    n.sort(key=int)
    answer+=n[0]
    answer+=' '
    answer+=n[-1]
    return answer