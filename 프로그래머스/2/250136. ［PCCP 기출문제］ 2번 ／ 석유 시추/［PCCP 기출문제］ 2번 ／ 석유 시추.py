from collections import *

dc = [1, 0, -1, 0]
dr = [0, 1, 0, -1]
    
def solution(land):
    answer = 0
    n_col = len(land[0])
    n_row = len(land)
    visited = [[0] * n_col for _ in range(n_row)]
    result = [0 for i in range(n_col)]
    
    def bfs(row, col):
        count = 0
        visited[row][col] = 1
        q = deque()
        q.append((row, col))
        min_col, max_col = col, col
        while q:
            c_row, c_col = q.popleft()

            min_col = min(min_col, c_col)
            max_col = max(max_col, c_col)

            count += 1

            for i in range(4):
                nr = c_row + dr[i]
                nc = c_col + dc[i]
                if nr < 0 or nc < 0 or nr >= n_row or nc >= n_col:
                    continue
                    
                if not visited[nr][nc] and land[nr][nc]:
                    q.append((nr, nc))
                    visited[nr][nc] = 1
                    
        for i in range(min_col, max_col+1):
            result[i] += count

    
    for r in range(n_row):
        for c in range(n_col):
            if not visited[r][c] and land[r][c]:
                bfs(r, c)
            
    return max(result)