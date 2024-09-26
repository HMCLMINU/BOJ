import heapq

INF = 1e9

def solution(N, road, K):
    answer = 0 
    
    times = [int(INF) for _ in range(N+1)]

    # set graph 
    graph = [[] for _ in range(N+1)]
    for info in road:
        graph[info[0]].append((info[1], info[2])) # (노드, 시간)
        graph[info[1]].append((info[0], info[2]))
    
    # dijkstra
    q = []
    heapq.heappush(q, (0, 1)) # (시간, 노드) 1번 노드 시작
    times[1] = 0
    
    while q:
        time, now = heapq.heappop(q)
        
        if times[now] < time:
            continue
        
        for adj in graph[now]:
            cost = time + adj[1]
            # 거쳐 온 경우가 현재보다 작다면 시간 업데이트 
            if cost < times[adj[0]]:
                times[adj[0]] = cost
                heapq.heappush(q, (cost, adj[0]))
    
    for time in times:
        if time <= K:
            answer+=1
    
    return answer