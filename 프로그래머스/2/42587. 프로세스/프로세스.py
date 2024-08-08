from collections import deque

def solution(priorities, location):
    answer = 0
    
    q = deque()
    for idx,v in enumerate(priorities):
        q.append([idx, v])
        
    priorities.sort(reverse=True)
    idx = 0
    while len(q) > 0:
        v = q.popleft()
        # 현재 작업의 우선순위가, 가장 먼저 해야할 작업인지 확인
        if v[1] == priorities[idx]:
            idx += 1
            # location과 같은지 확인
            if v[0] == location:
                return idx

            
        # 아니라면 다시 넣어야 함    
        else:
            q.append(v)
    