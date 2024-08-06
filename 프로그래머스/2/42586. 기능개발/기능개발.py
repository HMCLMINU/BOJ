from math import *
from collections import deque

def solution(progresses, speeds):
    daysLeft = list(map(lambda x: (ceil((100 - progresses[x]) / speeds[x])), range(len(progresses))))
    count = 1
    answer = []
    q = deque()
    q.append(daysLeft[0])
    idx = 1
    while len(q) != 0:
        v = q[0]
        try:
            if v >= daysLeft[idx]:
                q.append(daysLeft[idx])
            else:
                answer.append(len(q))
                q.clear()
                q.append(daysLeft[idx])
        except Exception:
            answer.append(len(q))
            break
        idx += 1

    return answer 