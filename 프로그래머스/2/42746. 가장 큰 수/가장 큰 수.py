from functools import cmp_to_key

def compare(s1, s2):
    if s1 + s2 < s2 + s1:
        return 1
    else:
        return -1
    
def solution(numbers):
    answer = ''
    n = list(map(lambda x: str(x), numbers))
    nn = sorted(n, key = cmp_to_key(compare))
    
    if nn[0] == '0':
        return '0'
    return str(''.join(nn))