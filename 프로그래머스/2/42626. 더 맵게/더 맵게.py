import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while scoville:
        first = heapq.heappop(scoville)
    
        if first >= K: break
        
        if scoville:
            second = heapq.heappop(scoville)
            heapq.heappush(scoville, first + second * 2)
        else:
            return -1
        
        answer += 1
                
    return answer