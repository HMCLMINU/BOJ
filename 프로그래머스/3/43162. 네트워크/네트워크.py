def dfs(graph, start, visited):
    if visited[start]:
        return

    visited[start] = 1
    for i in range(len(graph[start])):
        dfs(graph, graph[start][i], visited)      
    
def solution(n, computers):
    answer = 0
    graph = [[] for _ in range(len(computers))]
    visited = [0 for _ in range(len(computers))]

    for idx, computer in enumerate(computers):
        for i, c in enumerate(computer):
            if c == 1 and i != idx:
                graph[idx].append(i)
        
    for i in range(len(computers)):
        if visited[i]:
            continue
        dfs(graph, i, visited)
        answer += 1
            
    return answer