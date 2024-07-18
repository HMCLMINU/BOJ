from math import * 

def solution(n):
    
    # if int(sqrt(n)) == sqrt(n):
    #     return (sqrt(n) + 1)**2
    # else:
    #     return -1
    
    for i in range(1, int(sqrt(n))+1):
        if i*i == n:
            return (i+1)**2
    
    return -1
