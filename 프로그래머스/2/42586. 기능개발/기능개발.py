from math import *

def solution(progresses, speeds):
    daysLeft = list(map(lambda x: (ceil((100 - progresses[x]) / speeds[x])), range(len(progresses))))
    count = 1
    answer = []
    for i in range(len(daysLeft)):
        try: 
            if daysLeft[i] < daysLeft[i+1]:
                answer.append(count)
                count = 1
            else:
                daysLeft[i+1] = daysLeft[i]
                count += 1
                
        except Exception:
            answer.append(count)
            
    return answer 