def solution(bridge_length, weight, truck_weights):
    answer = 0
    in_time = [] # 트럭 진입 시간
    curr_w = [] # 다리 위 트럭
    time = 1
    
    while True:
        if in_time:
            if time - in_time[0] >= bridge_length:
                in_time.pop(0)
                curr_w.pop(0) 
            
        # curr_w가 weight 이하인 경우 현재 시간 큐에 넣기
        if truck_weights:
            if sum(curr_w)+truck_weights[0] <= weight:
                curr_w.append(truck_weights[0]) 
                truck_weights.pop(0)
                in_time.append(time)
        
        if len(curr_w) == 0:
            answer = time
            break
            
        time += 1
        
    return answer