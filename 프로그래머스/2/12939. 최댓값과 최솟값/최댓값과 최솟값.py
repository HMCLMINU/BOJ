def solution(s):
    # answer = ''
    # n = s.split(' ')
    # n.sort(key=int)
    # answer+=n[0]
    # answer+=' '
    # answer+=n[-1]
    
    n = list(map(int, s.split(' ')))
    return str(min(n)) + ' ' + str(max(n))
    # return answer