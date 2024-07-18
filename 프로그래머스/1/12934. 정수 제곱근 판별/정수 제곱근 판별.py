from math import * 

def solution(n):
    
    if int(sqrt(n)) == sqrt(n):
        return (sqrt(n) + 1)**2
    else:
        return -1
