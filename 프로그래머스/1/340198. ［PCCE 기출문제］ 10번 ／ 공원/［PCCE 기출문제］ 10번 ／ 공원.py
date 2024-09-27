def access(mat, park, st_row, st_col):
    for r in range(st_row, st_row+mat):
        for c in range(st_col, st_col+mat):
            if r < len(park) and c < len(park[0]):
                if park[r][c] != "-1":
                    return False
            else:
                return False
    return True
    
def solution(mats, park):
    answer = 0
    mats.sort(reverse=True)
    
    R = len(park)
    C = len(park[0])
    for mat in mats:
        for r in range(R):
            for c in range(C):
                if access(mat, park, r, c):
                    return mat
    
    return -1
    