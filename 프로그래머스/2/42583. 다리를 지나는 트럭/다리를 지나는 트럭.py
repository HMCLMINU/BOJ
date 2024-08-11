def solution(bridge_length, weight, truck_weights):
    q=[0]*bridge_length
    sec=0
    curr_w = 0
    while q:
        sec+=1
        curr_w -= q.pop(0)
        if truck_weights:
            if curr_w+truck_weights[0]<=weight:
                curr_w += truck_weights[0]
                q.append(truck_weights.pop(0))
            else:
                q.append(0)
    return sec