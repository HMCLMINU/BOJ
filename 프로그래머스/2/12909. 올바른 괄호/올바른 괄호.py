from collections import deque

def solution(s):    
    stk = deque()
    
    for c in s:
        if c == '(':
            stk.append(c)
            
        if c == ')':
            try:
                stk.pop()
            except Exception:
                return False
                
    return len(stk) == 0
                
                
